#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>
#include <Qtimer>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QFileDialog>
#include <cstdlib>
#include <ctime>

#include "array_manip.h"
#include "rule.h"
#include "save.h"

#include "global_vars.h"

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyPanelOpenGL(QWidget *parent = 0);

signals:
    // define mouseClick signal not used. here for future coding use
    void mouseClickEvent();

protected:
    void initializeGL();
    void paintGL();
    void keyPressEvent(QKeyEvent *e);


    void resizeGL(int width, int height);

    void mouseReleaseEvent ( QMouseEvent * e );
    void mousePressEvent ( QMouseEvent * e );

    void mouseMoveEvent( QMouseEvent * e);

public slots:

    bool run();
    bool stop();

    void process();    //runs game of life logic and repaints to screen
    bool eventFilter(QObject *obj, QEvent *event);  //here for future use
    void write_screen();    //write board to file
    void load_screen();    //load logical array file into game of life program
    void clear_board();    //clear board
    void start_stop_reset();    //utility function, used for future coding
    void capture_section();    //capture part of code
    void randomize();    //make random board

signals:
    void iterate_inc();    //increment counter
    void set_path_box(QString);    //set path of string

private:

    QPoint m_lastPoint, m_pointTwo; //First click for m_lastPoint, drag coordinate m_pointTwo
    // member variable - flag of click beginning
    bool m_mouseClick;
    bool m_mouseDrag;

    
    int gl_pointsz;

    int iter_ct;

    QTimer* timer;
    
    int board[WORLDSIZE][WORLDSIZE] = {};

    int board_temp[WORLDSIZE][WORLDSIZE] = {};
    int subboard[3][3] = {};    //required for game of life logic


};

#endif // MYPANELOPENGL_H
