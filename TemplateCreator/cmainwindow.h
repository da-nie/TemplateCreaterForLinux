#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <stdint.h>
#include <vector>

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT
public:
 //-перечисления---------------------------------------------------------------------------------------
 //типы шаблонов
 enum TEMPLATE_TYPE
 {
  TEMPLATE_TYPE_CLASS=0,
  TEMPLATE_TYPE_MFC_CLASS=1,
  TEMPLATE_TYPE_MFC_DV_CLASS=2,
  TEMPLATE_TYPE_INTERFACE=3
 };
 //-структуры------------------------------------------------------------------------------------------
 //-константы------------------------------------------------------------------------------------------
private:
 //-переменные-----------------------------------------------------------------------------------------
 std::vector<std::pair<std::string,size_t> > TypeList;//список типов
public:
 //-конструктор----------------------------------------------------------------------------------------
 explicit CMainWindow(QWidget *parent=0);
 //-Деструктор-----------------------------------------------------------------------------------------
  ~CMainWindow();
public:
 //-Открытые функции класса----------------------------------------------------------------------------
private:
 //-Закрытые функции класса----------------------------------------------------------------------------
 void CreateTypeList(void);//создать список типов создаваемых объектов

private slots:
    void on_CPushButton_Create_clicked();

private:
    Ui::CMainWindow *ui;
};

#endif // CMAINWINDOW_H
