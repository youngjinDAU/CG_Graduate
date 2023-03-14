#include "Viewer.h"

#include <fstream>
#include <QKeyEvent>
#include <sstream>

Viewer::Viewer(QWidget* parent)
{
	setParent(parent);
}

void Viewer::initializeGL()
{
	restoreStateFromFile();
	glClearColor(1, 1, 1, 1);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_NORMALIZE);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glFrontFace(GL_CCW);
	//glEnable(GL_LIGHTING);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	GLfloat ambient[] = { 0.1,0.1,0.1 };
	GLfloat diffuse[] = { 0.6,0.6,0.6 };
	GLfloat light0Pos[] = { 100,100,100,0 };
	GLfloat light1Pos[] = { -100,100,100,0 };
	GLfloat specular[] = { 0.7,0.7,0.7 };
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
	glEnable(GL_LIGHT1);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 10);
	dc.Init();
}

void Viewer::draw()
{
	dc.Draw();
}

void Viewer::keyPressEvent(QKeyEvent* e)
{
	int key = e->key();
	if (key >= Qt::Key_0 && key <= Qt::Key_9 || key == Qt::Key_Plus || key == Qt::Key_Minus)
	{
		NumKeyProcess(key);
	}
	if (key == Qt::Key_Comma)
	{

		double rad = camera()->sceneRadius();
		rad *= 10.0;
		printf("radius : %f\n", rad);
		camera()->setSceneRadius(rad);
	}
	else if (key == Qt::Key_Period)
	{
		double rad = camera()->sceneRadius();
		rad /= 10.0;
		printf("radius : %f\n", rad);
		camera()->setSceneRadius(rad);
	}
	else if (key == Qt::Key_Up)
		dc.arrowNum0++;
	else if (key == Qt::Key_Down)
		dc.arrowNum0--;
	else if (key == Qt::Key_Left)
		dc.arrowNum1--;
	else if (key == Qt::Key_Right)
		dc.arrowNum1++;
	else if (key == Qt::Key_S)
	{
		// time_t now;
		// now = time(NULL);
		// std::stringstream ss;
		// ss << "xyz_" << now << ".jpg";
		// std::string s = ss.str();
		// setSnapshotQuality(99);
		// setSnapshotFormat(QString("BMP"));
		// saveSnapshot(QString(s.c_str()), true);
	}
	else if (key == Qt::Key_N)
	{
		if (animationIsStarted())
			stopAnimation();
		else
			startAnimation();
	}
	else if (key == Qt::Key_K)
	{
		saveStateToFile();
	}
	else if (key == Qt::Key_L)
	{
		restoreStateFromFile();
	}
	else if (key == Qt::Key_Insert)
	{
	}
	else
		QGLViewerOrtho::keyPressEvent(e);

	updateGL();


}

void Viewer::mousePressEvent(QMouseEvent* e)
{
	QGLViewerOrtho::mousePressEvent(e);
}

void Viewer::mouseMoveEvent(QMouseEvent* e)
{
	QGLViewerOrtho::mouseMoveEvent(e);
}

void Viewer::mouseReleaseEvent(QMouseEvent* e)
{
	QGLViewerOrtho::mouseReleaseEvent(e);
}

void Viewer::NumKeyProcess(int key)
{
}

void Viewer::animate()
{

}