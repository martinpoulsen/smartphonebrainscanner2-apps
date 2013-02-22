#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include <model.h>
#include <sbs2common.h>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void updateColorForVertex(int vertex, double r, double g, double b, double a);

private:
    void paintGL ();
    void initializeGL ();
    void resizeGL(int w, int h);
    void timerEvent(QTimerEvent *e);

    //Interaction
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

    //Freqs
    void resetFreqs();

    void setInfoText(QString text);

private:
    double aspectRatio;

    QMatrix4x4 mainModelView;
    QVector3D camera;
    Model* model;
    QBasicTimer *timer;


    //Interaction
    QPoint dragLastPosition;
    QPoint dragStartPosition;
    bool dragging;
    qreal dragX;
    qreal dragY;

    QRect quitRect;
    QRect toggleRect;
    QRect toggleRectEmocap;

    QRect deltaRect;
    QRect thetaRect;
    QRect alphaRect;
    QRect lowBetaRect;
    QRect betaRect;

    QRect rotationRect;

    int deltaOn;
    int thetaOn;
    int alphaOn;
    int lowBetaOn;
    int betaOn;

    int sourceRecOn;

    double gyroX;
    double gyroY;

    QPixmap logoPixmap;
    QRect logoRect;
    int infoPressed;

    QRect websiteRect;
    QRect infoRect;

    int headMovementOn;
    int zeroRotation;

    QPixmap epicenterPixmap;

    QRect infoTextRect;
    QString infoText;

    int devicePresent;
    int dataFlowing;

    QRect rect1;
    QRect rect2;
    double value1;
    double value2;

signals:
    void turnSourceReconstructionPowerOff();
    void turnSourceReconstructionPowerOn(int samples, int delta, int modelUpdateLength, int modelUpdateDelta, QString hardware);
    void changeBand(QString name);

public slots:
    void quit();
    void changeFrequency(QString name);
    void updateGyroX(double gyroX_);
    void updateGyroY(double gyroY_);
    void deviceFound(QMap<QString, QVariant> params);
    void updateValues(double value1_, double value2_);

};

#endif // GLWIDGET_H