#include <QtGui>
#include "renderarea.h"
#include <vector>
#include <cmath>
#include <QtMath>
#include <QColor>
RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    /*mmmmm what s that*/
    //shape = foo;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    /*mmmmmmmmmmm*/

}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

/*fine 1*/
void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}
/*end fine 1*/

/*inputing*/
void RenderArea::setNum(int num)
{
    this->num = num;
    update();
}
/*end*/


/*Koch*/
void generateKoch(std::vector<QLine>& lines,unsigned int n){
    QLine temp;
    QPoint p1,p2,p3,p4,p5;
    double x3,x4,x5,y3,y4,y5;
    for(unsigned int i = 0 ;i < n; i++)
    {
        p1 = lines[i].p1();
        p2 = lines[i].p2();

        x3 = ((p1.x()-p2.x())/3);
        y3 = (p1.y()-p2.y())/3;
        if(x3<0){
            x5 = p1.x()-(2*x3);
            x3 = p1.x()-x3;
        }
        else{
            x5 = x3 + p2.x();
            x3 = p2.x()+(2*x3);
        }
        if(y3<0){
            y5 = p1.y()-(2*y3);
            y3 = p1.y()-y3;
        }
        else{
            y5 = p2.y()+y3;
            y3 = p2.y()+(2*y3);
        }
        p3.setX(x3);
        p3.setY(y3);



        p5.setX(x5);
        p5.setY(y5);


        x4 = x5 - x3;
        y4 = y5 - y3;
        double xNew = (x4 * qCos(M_PI/3)) + (y4 * qSin(M_PI/3) );
        double yNew = -(x4 * qSin(M_PI/3) ) + (y4 * qCos(M_PI/3));

        p4.setX(xNew + x3);
        p4.setY(yNew + y3);





        lines[i].setP2(p3);
        temp.setP1(p3);
        temp.setP2(p4);
        lines.push_back(temp);
        temp.setP1(p4);
        temp.setP2(p5);
        lines.push_back(temp);
        temp.setP1(p5);
        temp.setP2(p2);
        lines.push_back(temp);
    }
}
/*end Koch*/

/*Sierpinski*/
void generateSierpinski(std::vector<QLine>& lines,unsigned int n){
    QLine temp;
    QPoint p1,p2,p3,p4,p5;
    double x1,x2,x3,x4,x5,y1,y2,y3,y4,y5;
     for(unsigned int i = 0 ;i < n; i++)
     {
         temp = lines[i];
         x4 = temp.p1().x();
         y4 = temp.p1().y();
         x5 = temp.p2().x();
         y5 = temp.p2().y();
         if(y5!=y4)continue;
         y3 = y4;
         x3 = (x4+x5)/2;
         x2 = x5;
         y2 = y5;

         x2 = x2 - x3;
         y2 = y2 - y3;
         double xNew = (x2 * qCos(M_PI/3)) + (y2 * qSin(M_PI/3) ) + x3;
         double yNew = -(x2 * qSin(M_PI/3) ) + (y2 * qCos(M_PI/3)) + y3;
         x2 = xNew;
         y2 = yNew;

         y1 = y2;
         x1 = x2 - (temp.p2().x()-x3);

         p1.setX(x1);
         p1.setY(y1);
         p2.setX(x2);
         p2.setY(y2);
         p3.setX(x3);
         p3.setY(y3);
         p4.setX(x4);
         p4.setY(y4);
         p5.setX(x5);
         p5.setY(y5);

         temp.setP1(p1);
         temp.setP2(p2);
         lines.push_back(temp);
         temp.setP1(p3);
         temp.setP2(p2);
         lines.push_back(temp);
         temp.setP1(p1);
         temp.setP2(p3);
         lines.push_back(temp);
         temp.setP1(p1);
         temp.setP2(p3);
         lines.push_back(temp);
         temp.setP1(p3);
         temp.setP2(p5);
         lines.push_back(temp);
         temp.setP1(p4);
         temp.setP2(p3);
         lines.push_back(temp);
     }

}
/*end Sierpinski*/

/*Tree*/
void generateTree(std::vector<QLine>& lines, unsigned int n,std::vector<QLine>& Ls,double length)
{
    QLine temp;
    std::vector<QLine> newLs;
    QPoint p1,p2,p3;
    double x1,x2,x3,y1,y2,y3;
    for(unsigned int i = 0 ;i < n; i++)
    {
        temp = Ls[i];
        x1 = temp.p1().x();
        y1 = temp.p1().y();
        x2 = temp.p2().x();
        y2 = temp.p2().y();
        double dx = x2-x1;
        double dy = y2-y1;
        dx *= (-1+sqrt(5))/2;//lenght
        dy *= (-1+sqrt(5))/2;//lenght
        x1=x2;
        y1=y2;
        x2=x2+dx;
        y2=y2+dy;
        x3=x2;
        y3=y2;

        x2 = x2 - x1;
        y2 = y2 - y1;
        double xNew = (x2 * qCos(M_PI/6)) - (y2 * qSin(M_PI/6))+x1;//angle 68
        double yNew = (x2 * qSin(M_PI/6)) + (y2 * qCos(M_PI/6))+y1;//angle 68
        x2 = xNew;
        y2 = yNew;


        x3 = x3 - x1;
        y3 = y3 - y1;
        xNew = (x3 * qCos(M_PI/6)) + (y3 * qSin(M_PI/6) ) +x1;//angle here
        yNew = -(x3 * qSin(M_PI/6) ) + (y3 * qCos(M_PI/6)) +y1;//angle here
        x3 = xNew;
        y3 = yNew;


        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
        p3.setX(x3);
        p3.setY(y3);
        temp.setP1(p1);
        temp.setP2(p2);
        lines.push_back(temp);
        newLs.push_back(temp);
        temp.setP2(p3);
        lines.push_back(temp);
        newLs.push_back(temp);
    }
    length *= (-1+sqrt(5))/2;
    if(length<1)return;
    else generateTree(lines, newLs.size(),newLs,length);
}
/*end Tree*/


void RenderArea::paintEvent(QPaintEvent * /*event*/)
{
    /*aded this reclessly*/

    QRect rect(10, 20, 80, 60);
    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);


    QPainter painter(this);

    switch (shape) {
    case foo:
        break;
    case Sierpinski:
    {
        QLine temp;
        std::vector<QLine> lines;
        QPoint p;
        p.setX(120);
        p.setY(560);
        temp.setP1(p);
        p.setX(750);
        p.setY(560);
        temp.setP2(p);
        lines.push_back(temp);

        double x=(temp.p2().x() - temp.p1().x());
        double y=(temp.p2().y() - temp.p1().y());
        double xNew = (x * 0.5) + (y * sqrt(3) / 2 ) + temp.p1().x();
        double yNew = -(x * sqrt(3) / 2 ) + (y * 0.5) + temp.p1().y();
        temp.setP1(p);
        p.setX(xNew);
        p.setY(yNew);
        temp.setP2(p);
        lines.push_back(temp);
        temp.setP1(p);
        p.setX(120);
        p.setY(560);
        temp.setP2(p);
        lines.push_back(temp);

        if(num>11)num=11;

        for(int i=0;i<num;i++)
            generateSierpinski(lines,lines.size());
        for(int j=0;j<lines.size();j++)
            painter.drawLine(lines[j]);
    }
        break;
    case Koch:
    {
        QLine temp;
        std::vector<QLine> lines;
        QPoint p;
        p.setX(50);
        p.setY(400);
        temp.setP1(p);
        p.setX(820);
        p.setY(400);
        temp.setP2(p);
        lines.push_back(temp);
        if(num>12)num=12;
        for(int i=0;i<num/*12*/;i++)
            generateKoch(lines,lines.size());
        for(int j=0;j<lines.size();j++)
            painter.drawLine(lines[j]);
    }
        break;
    case Tree:
    {
        QLine temp;
        std::vector<QLine> lines;
        QPoint p;
        p.setX(435);
        p.setY(605);
        temp.setP1(p);
        p.setX(435);
        p.setY(370);
        temp.setP2(p);
        lines.push_back(temp);
        generateTree(lines,1,lines,235);
        for(int j=0;j<lines.size();j++)
            painter.drawLine(lines[j]);
    }
        break;

    case Chaos1:
    {
        //painter.setPen(QPen(Qt::black, 3));
        QPoint p;
        QPoint points[3];
        p.setX(50);
        p.setY(580);
        points[0] = p;
        painter.drawPoint(p);
        p.setX(840);
        p.setY(420);
        points[1] = p;
        painter.drawPoint(p);
        p.setX(330);
        p.setY(60);
        points[2] = p;
        painter.drawPoint(p);
        p.setX(300);
        p.setY(300);
        painter.drawPoint(p);
        if (num>100000)num=100000;
        for(unsigned int i = 0; i < num/*100000*/;i++)
        {
            quint32 value = QRandomGenerator::global()->generate();
            int test = value % 3;
            p.setX((p.x()+points[test].x())/2);
            p.setY((p.y()+points[test].y())/2);
            painter.drawPoint(p);
        }
    }
        break;
    case Chaos2:
    {
        QPoint p;
        QPoint points[4];
        p.setX(133);
        p.setY(0);
        points[0] = p;
        painter.drawPoint(p);
        p.setX(738);
        p.setY(0);
        points[1] = p;
        painter.drawPoint(p);
        p.setX(738);
        p.setY(605);
        points[2] = p;
        painter.drawPoint(p);
        p.setX(133);
        p.setY(605);
        points[3] = p;
        painter.drawPoint(p);
        p.setX(300);
        p.setY(300);
        painter.drawPoint(p);
        int a = -2;
        for(unsigned int i = 0; i < num/*100000*/;i++)
        {
            int test;
            do{
                quint32 value = QRandomGenerator::global()->generate();
                test = value % 4;
            }while((test == ((a+1) % 4)));
            if(i>0) a=test;
            p.setX((p.x()+points[test].x())/2);
            p.setY((p.y()+points[test].y())/2);
            painter.drawPoint(p);
        }
    }
        break;
    case Chaos3:
    {
        QPoint p;
        QPoint points[5];
        p.setX(605);
        p.setY(562);
        points[0] = p;
        painter.drawPoint(p);
        p.setX(265);
        p.setY(562);
        points[1] = p;
        painter.drawPoint(p);
        p.setX(710);
        p.setY(238);
        points[2] = p;
        painter.drawPoint(p);
        p.setX(434);
        p.setY(38);
        points[3] = p;
        painter.drawPoint(p);
        p.setX(158);
        p.setY(238);
        points[4] = p;
        painter.drawPoint(p);
        p.setX(300);
        p.setY(300);
        painter.drawPoint(p);
        for(unsigned int i = 0; i < num/*100000*/;i++)
        {
            int test;
            do{
                quint32 value = QRandomGenerator::global()->generate();
                test = value % 5;
            }while(false);
            p.setX((p.x()+points[test].x())/2);
            p.setY((p.y()+points[test].y())/2);
            painter.drawPoint(p);
        }
    }

        break;
    case Barnsley:
    {
        QPen pen;
        QColor color(0, 100, 0, 255);
        pen.setColor(color);
        painter.setPen(pen);
        QPoint p;
        p.setX(500);
        p.setY(500);
        painter.drawPoint(p);
        double lastX = 0;
        double lastY = 0;
        for(unsigned int i = 0; i < num/*100000*/;i++)
        {
            quint32 value = QRandomGenerator::global()->generate();
            double test = value % 100;
            test /= 100;
            double newX,newY;
            double x=lastX-500;
            double y=lastY + 500;
            if (test < 0.01){
                newX =  0;
                newY =  0.16 * y;
            }
            else if (test < 0.86){
                newX =  0.85 * x + 0.04 * y;
                newY = -0.04 * x + 0.85 * y + 1.6;
            }
            else if (test < 0.93){
                newX =  0.20 * x - 0.26 * y;
                newY =  0.23 * x + 0.22 * y + 1.6;
            }
            else {
                newX = -0.15 * x + 0.28 * y;
                newY =  0.26 * x + 0.24 * y + 0.44;
            }
            lastX = newX;
            lastY = newY;
            p.setX((newX/7) + 500);
            p.setY(-(newY/7) + 500);

            painter.drawPoint(p);
        }
    }
        break;
    case Julia:
    {
        painter.setPen(QPen(Qt::black, 3));
        QPen pen;
        QPoint p;
        painter.drawPoint(p);
        for(double x = 0; x < 872; x++){
            for(double y = 0; y < 605; y++){
                x -= 436;
                y -= 302;
                double a = x/290;
                double b = y/201;
                double a0 = a;
                double b0 = b;

                int n;
                for(n= 0; n < 255; n++){
                    double r = (a * a) - (b * b);
                    double i = 2 * a * b;
                    a = r - 0.70176;
                    b = i - 0.3842;
                    int c = (a + b);
                    if((abs(c))>20) break;
                }

                n = 255 - n;
                x += 436;
                y += 302;
                p.setX(x);
                p.setY(y);
                QColor color(n, n, n, 255);
                pen.setColor(color);
                pen.setWidth(5);
                painter.setPen(pen);
                painter.drawPoint(p);
            }
        }
    }
        break;
    case Mandelbrot:
    {
        QPen pen;
        QPoint p;
        painter.drawPoint(p);
        for(double x = 0; x < 872; x++){
            for(double y = 0; y < 605; y++){
                x -= 520;
                y -= 302;
                double a = x/290;
                double b = y/201;
                double a0 = a;
                double b0 = b;

                int n;
                for(n= 0; n < 255; n++){
                    double r = (a * a) - (b * b);
                    double i = 2 * a * b;
                    a = r + a0;
                    b = i + b0;
                    int c = (a + b);
                    if((abs(c))>13) break;
                }

                n = 255 - n;
                x += 520;
                y += 302;
                p.setX(x);
                p.setY(y);
                QColor color(n, n, n, 255);
                pen.setColor(color);
                painter.setPen(pen);
                painter.drawPoint(p);
            }
        }
    }
        break;

    case Text:
        painter.drawText(rect, Qt::AlignCenter, tr("Qt by\nNokia"));
        break;
    }
    painter.restore();



    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
    /*hhhhhhhhhhh*/
}
