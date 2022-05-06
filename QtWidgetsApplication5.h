#pragma once
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication5.h"
#include<QFileInfo>
#include<QString>
#include<QStringList>
#include <QFileDialog>
#include<qsqltablemodel>
#include<QListWidgetItem>
class QtWidgetsApplication5 : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlTableModel* sql_mod;
	void get_text();
    void open_database(QString path);
    void set_table(QListWidgetItem *item);
    QtWidgetsApplication5(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtWidgetsApplication5Class ui;
};
