#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>
#include <Qtimer>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QFileDialog>

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


protected:
    void initializeGL();
    void paintGL();
    void keyPressEvent(QKeyEvent *e);


    void resizeGL(int width, int height);

public slots:

    bool run();
    bool stop();

    void process();
    bool eventFilter(QObject *obj, QEvent *event);
    void write_screen();
    void load_screen();
    void clear_board();
    void start_stop_reset();
    void capture_section();

signals:
    void iterate_inc();
    void set_path_box(QString);

private:

    int iter_ct;
    QTimer* timer;
    int board[WORLDSIZE][WORLDSIZE] = {};

    int board_temp[WORLDSIZE][WORLDSIZE] = {};
    int subboard[3][3] = {};


};

#endif // MYPANELOPENGL_H
