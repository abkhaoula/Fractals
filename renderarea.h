#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    /*fine 1*/
    enum Shape { foo,Sierpinski, Koch, Tree, Chaos1, Chaos2,
                      Chaos3, Barnsley, Mandelbrot, Julia, Text };
    /*end fine 1*/

    /*spin box*/
    /*end spin*/


    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

signals:

public slots:
    /*fine 1*/
    void setShape(Shape shape);
    /*end fine 1*/

    /*inputng*/
    void setNum(int num);
    /*end inp*/

protected:
     void paintEvent(QPaintEvent *event);

private:
     /*fine 1*/
     Shape shape;
     /*end fine 1*/
/*inputing*/
     int num;
};

#endif // RENDERAREA_H
