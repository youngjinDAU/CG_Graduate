#pragma once
#include "QGLViewer/manipulatedFrame.h"
#include "QGLViewer/qglviewerortho.h"
#include <chrono>

#include "DrawComponent.h"

//#include "DrawComponent.h"

class Viewer : public QGLViewerOrtho
{
	Q_OBJECT

		MN::DrawComponent dc;
public:
	Viewer(QWidget* parent);
	virtual void initializeGL() override;
	virtual void draw() override;
	virtual void keyPressEvent(QKeyEvent* e) override;
	virtual void mousePressEvent(QMouseEvent* e) override;
	virtual void mouseMoveEvent(QMouseEvent* e) override;
	virtual void mouseReleaseEvent(QMouseEvent* e) override;
	virtual void animate();
	void NumKeyProcess(int key);

	GLuint programID;
	bool useShader = false;
	int animateIdx = 0;
};