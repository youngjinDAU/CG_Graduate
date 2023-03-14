#pragma once

#include <QtWidgets/QWidget>
#include "ui_CG_Graduate.h"

class CG_Graduate : public QWidget
{
    Q_OBJECT

public:
    CG_Graduate(QWidget *parent = nullptr);
    ~CG_Graduate();

private:
    Ui::CG_GraduateClass ui;
};
