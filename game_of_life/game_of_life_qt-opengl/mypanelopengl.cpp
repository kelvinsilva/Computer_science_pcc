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
    board[8][6] = 1;
    board[8][7] = 1;
    board[8][8] = 1;
    board[7][8] = 1;
    board[6][7] = 1;
    this->installEventFilter(this);
    iter_ct = 0;

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

    float placement_x = -.86;
    float placement_y = .86;
    float space = placement_x;
    float new_line = placement_y;

    glPointSize(10);
    for(int i = 0; i < WORLDSIZE; i++)
    {
         for(int j = 0; j < WORLDSIZE; j++){

            if(board[i][j] == 1)
                glColor3f(0.0f, 0.0f, 2.0f);
            else if(board[i][j] == 0){
                glColor3f(2.0f, 0.0, 0.0f);
            }if (board[i][j] == 2){
                glColor3f(2.0f, 0.0, 1.0f);

            }

            glBegin(GL_POINTS);
                glVertex2f(space, new_line);
            glEnd();
            space += .05;
        }
        space = placement_x;
        new_line -= .05;
    }
    new_line = placement_y;

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
        border_reflection(board);
        rule(board, board_temp, subboard);
        border_reflection(board_temp);
        copy_board(board, board_temp);
        emit iterate_inc();
        repaint();
        updateGL();
}


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

void MyPanelOpenGL::write_screen(){

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File To Directory"), "", tr("Logical Array (*.lar)"));
    fstream file_write(fileName.toLocal8Bit().data(), fstream::out);
    out_file_board(file_write, board);
    file_write.close();
    //out_file_board(fstream &fout, int board[][WORLDSIZE]){
    //out_file_board
    emit set_path_box(fileName);
}

void MyPanelOpenGL::load_screen(){

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Logical Array (*.lar)"));
    fstream file_read(fileName.toLocal8Bit().data(), fstream::in);
    load_file(file_read, board);
    file_read.close();
    emit set_path_box(fileName);
}

void MyPanelOpenGL::clear_board(){

        init_board(board);
        init_board(board_temp);


}

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

