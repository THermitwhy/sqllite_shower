#include "QtWidgetsApplication5.h"
#include <QtWidgets/QPushButton>

QtWidgetsApplication5::QtWidgetsApplication5(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    sql_mod=new QSqlTableModel();
    ui.setupUi(this);
    
    ui.bt1->setText("251");
    ui.list1->addItem("1");
    connect(ui.bt1, &QPushButton::clicked, this, &QtWidgetsApplication5::get_text);
    connect(ui.list1, &QListWidget::itemClicked, this, &QtWidgetsApplication5::set_table);
	
    
}

void QtWidgetsApplication5::get_text() {
    QString file_full, file_name, file_path, file_suffix;
    QFileInfo fileinfo;
    file_full = QFileDialog::getOpenFileName(this);
    fileinfo = QFileInfo(file_full);
    //文件名
    file_name = fileinfo.fileName();
    //文件后缀
    file_suffix = fileinfo.suffix();
        //绝对路径
    file_path = fileinfo.absolutePath();
    ui.le1->setText(file_path+"/"+file_name);
    open_database(file_path + "/" + file_name);
   
}

void QtWidgetsApplication5::open_database(QString path) {
	db.setDatabaseName(path);
    if (!db.open()) {
        
    }
	else {
		qDebug() << "Connected...";
        qDebug() << "Failed to connect to database";
        QStringList lis = db.tables();
        QStringListIterator iteror(lis);
        ui.list1->addItems(lis);
        while (iteror.hasNext())
        {
            QString name = iteror.next().toLocal8Bit();
            qDebug() << name;
        }
	}
}

void QtWidgetsApplication5::set_table(QListWidgetItem* item) {
	sql_mod->setTable(item->text());
    ui.tableView1->setModel(sql_mod);
    if (!sql_mod->select())
    {
        qDebug() << "数据查询失败!!" ;
        return;
    }
}