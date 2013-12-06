#include "mypanelopengl.h"
#include <QDebug>
#include <QLabel>

#include "GL/glu.h"
#include <cmath>
#include <iostream>



using namespace std;


MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    init_board(board);
    init_board(board_temp);
    board[8][6] = 1;    //set initial state as a glider....
    board[8][7] = 1;
    board[8][8] = 1;
    board[7][8] = 1;
    board[6][7] = 1;
    this->installEventFilter(this); //not sure if needed. test to see if this line needs to be included
    iter_ct = 0;    //set iteration count to zero
    m_mouseClick = false;    //mouseclick and drag states
    m_mouseDrag = false;
    gl_pointsz = 6;    //gl point size of each point

}

//mouse click methods

void MyPanelOpenGL::mousePressEvent ( QMouseEvent * e )
{
    // set the flag meaning "click begin"
    m_mouseClick = true;
    // store click position
    m_lastPoint = e->pos();


        int i = (int) (m_lastPoint.y()/gl_pointsz);    //formula to convert coordinate to int array position
        int j = (int) (m_lastPoint.x()/gl_pointsz);

        if (i < WORLDSIZE-1 && j < WORLDSIZE-1 && i > 0 && j > 0){    //if cursor is within the boundaries, then set the board cell alive
            board[i][j] = 1;
        }
            repaint();
            updateGL();
}

void MyPanelOpenGL::mouseMoveEvent( QMouseEvent * e){

    if (m_mouseClick){
    
        m_mouseDrag = true;    //set mouse drag state to true, used in mouseRelease to see if a use merely clicked or also dragged
        m_pointTwo = e-> pos();    //store coordinate of mouse movement
        int i = (int) (m_pointTwo.y()/gl_pointsz);    //convert to array position
        int j = (int) (m_pointTwo.x()/gl_pointsz);

     
        int tempbd[WORLDSIZE][WORLDSIZE]; //make a temporary board to store current board state because we will draw on board
        copy_board(tempbd, board);    //copy current state to temp board
        x_ = m_lastPoint.x()/gl_pointsz;    //convert initial click (see above function) AND mouse drag click to array coordiantes
        y_ = m_lastPoint.y()/gl_pointsz;
        x_x = m_pointTwo.x()/gl_pointsz;
        y_y = m_pointTwo.y()/gl_pointsz;
        
        //we only need two coordinates and their respective x and y values to draw a rectangle
        
        //the ternary operator in this loop determines if user is dragginf rom top left to bottom right
        //or dragging bottom right to top left
        //We do this to make sure we are going smaller --> bigger incrementation to fill the board with the corrent contents
        if (x_ > 0 && y_ > 0 && x_x > 0 && y_y > 0
            && x_ < WORLDSIZE-1 && x_x < WORLDSIZE-1 && y_ < WORLDSIZE-1 && y_y < WORLDSIZE-1){
            for (int i = ((y_ < y_y) ? y_ : y_y);
                 i < ((y_ > y_y) ? y_ : y_y);
                 i++ ){

                board[i][x_] = 3;    //set to three for a white tile. see paintgl function
                board[i][x_x] = 3;
            }
            for (int j = ((x_ < x_x) ? x_ : x_x);
                 j < ((x_ > x_x) ? x_ : x_x);
                 j++ ){

                board[y_][j] = 3;
                board[y_y][j] = 3;
            }
            //draw board with rectangle to screen. DO NOT RUN GAME OF LIFE LOGIC. ONLY DRAWING
            repaint();
            updateGL();
            
            //copy temp board back to board. eliminates the rectangular integer 3 from board.
            copy_board(board, tempbd);    
        }
    }

}

void MyPanelOpenGL::mouseReleaseEvent ( QMouseEvent * e )
{
    // check if cursor not moved since click beginning
    //if ((m_mouseClick) && (e->pos() == m_lastPoint)){
        // do something: for example emit Click signal
        //emit mouseClickEvent();
        //x_, y_, x_x, y_y

            //this->capture_section();



    //cout  << "point: " << x_ << " " << y_ << " " << x_x << " " << y_y;
    //MessageBox(NULL, NULL, NULL, NULL);
   
    if (m_mouseDrag){

        capture_section();
    }

    x_ = 0;
    y_ = 0;
    x_x = 0;
    y_y = 0;
    m_mouseClick = false;
    m_mouseDrag = false;

}

void MyPanelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void MyPanelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //    static float i(0.01),j(0.007);

    double placement_x = -.98;
    double placement_y = .98;
    double space = placement_x;
    double new_line = placement_y;

    glPointSize(gl_pointsz);
    for(int i = 0; i < WORLDSIZE; i++)
    {
         for(int j = 0; j < WORLDSIZE; j++){

            if(board[i][j] == 1)    //Alive cell is blue
                glColor3f(0.0f, 0.0f, 2.0f);
            else if(board[i][j] == 0){    //dead cell is black
                glColor3f(0.0f, 0.0, 0.0f);
            }if (board[i][j] == 2){    //borders are pink
                glColor3f(2.0f, 0.0, 1.0f);
            }else if (board[i][j] == 3){    //drag element is white
                glColor3f(2.0f, 2.0f, 2.0f);
            }
            glBegin(GL_POINTS);
                glVertex2d(space, new_line);
            glEnd();



                    /*

                      glVertex2f(space + ((j - 1) * width),  - ((i - 1) * width));
                      glVertex2f(space + (j * width), y - ((i - 1) * width));
                      glVertex2f(space + (j * width), y - (i * width));
                      glVertex2f(space + ((j - 1) * width), y - (i * width));


            glEnd();*/
            space += .023; //spacing in between
        }
        space = placement_x;
        new_line -= .026;    //spacing in between
    }
    new_line = placement_y;

   /* glColor3f(2.0, 2.0, 2.0);
    glBegin(GL_QUADS);

        glVertex2d(x_/100, y_/100);
        glVertex2d( x_/100, y_y/100);
        glVertex2d( x_x/100, y_/100);
        glVertex2d(x_x/100,y_y/100);
        //glVertex2d(top_left_x, top_left_y);
    glEnd();*/
}


void MyPanelOpenGL::keyPressEvent(QKeyEvent *e)
{
    /*switch(e->key())
    {
    case Qt::Key_Down:
        run();
        break;
    case Qt::Key_Up:
        stop();
        break;
    }*/
}

bool MyPanelOpenGL::run()
{
    if(!timer)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(process()));
        timer->start(delay);
        return true; //was running
    }
    return false; //was stopped
}

bool MyPanelOpenGL::stop()
{
    if(timer)
    {
        delete timer;
        timer = NULL;
        return true; //was running
    }
    return false; //was stopped
}

void MyPanelOpenGL::process()
{
        //{game of life logic
        border_reflection(board);
        rule(board, board_temp, subboard);
        border_reflection(board_temp);
        copy_board(board, board_temp);
        //}game of life logic
        
        
        emit iterate_inc();
        repaint();
        updateGL();
}

//does nothing, deprecated
void MyPanelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width,(GLint) height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f,(GLfloat)width/(GLfloat)height,1.0f, 100.0f );

}

bool MyPanelOpenGL::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    //ui->statusBar()->showMessage(QString("Mouse move ").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
    //cout << "mousemove";

    //this->label1->setText("Move");
  }

  return false;
}

void MyPanelOpenGL::write_screen(){    //save all of screen and write to file

    //open file dialog
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File To Directory"), "", tr("Logical Array (*.lar)"));
    fstream file_write(fileName.toLocal8Bit().data(), fstream::out);
    out_file_board(file_write, board);
    file_write.close();
    //out_file_board(fstream &fout, int board[][WORLDSIZE]){
    //out_file_board
    emit set_path_box(fileName); //change text in the mainwindow text edit
}

void MyPanelOpenGL::load_screen(){

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Logical Array (*.lar)"));
    
    //write
    fstream file_read(fileName.toLocal8Bit().data(), fstream::in);
    load_file(file_read, board);
    file_read.close();
    emit set_path_box(fileName);
}

void MyPanelOpenGL::clear_board(){

        init_board(board);    //clear board and process to display on screen.
        init_board(board_temp);
        repaint();
        updateGL();
}

//utility function
void MyPanelOpenGL::start_stop_reset(){
    if(stop())
        run();
}

void MyPanelOpenGL::capture_section(){

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Logical Array (*.lar)"));
    fstream file_write(fileName.toLocal8Bit().data(), fstream::out);
    out_file_board(file_write, board, x_, y_, x_x, y_y);

    file_write.close();
    emit set_path_box(fileName);
}

//randomize board contents
void MyPanelOpenGL::randomize(){

    srand(time(NULL));

    for (int i = 0; i < WORLDSIZE*WORLDSIZE; i++){
        board[rand()%(WORLDSIZE-3)+1][rand()%(WORLDSIZE-3)+1] = 1;
    }
    process();
}
