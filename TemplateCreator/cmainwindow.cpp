//====================================================================================================
//подключаемые библиотеки
//====================================================================================================
#include "cmainwindow.h"
#include "ui_cmainwindow.h"
#include "craiifilein.h"
#include "craiifileout.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <functional>

void CreateOutputFile(std::string name,std::string file_name,std::string class_name,std::string define_name,std::string description,std::string tempate_file_name,std::string output_file_name);



CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

 CreateTypeList();

 auto list_function=[this](std::pair<std::string,size_t> &element)
 {
  ui->CComboBox_Type->addItem(element.first.c_str());
 };
 std::for_each(TypeList.begin(),TypeList.end(),list_function);
 ui->CComboBox_Type->setCurrentIndex(0);
 ui->CLineEdit_Description->setText("Описание класса");
 ui->CLineEdit_Name->setText("");
}

CMainWindow::~CMainWindow()
{
 delete(ui);
}

//====================================================================================================
//закрытые функции класса
//====================================================================================================

//----------------------------------------------------------------------------------------------------
//создать список типов создаваемых объектов
//----------------------------------------------------------------------------------------------------
void CMainWindow::CreateTypeList(void)
{
 TypeList.clear();
 TypeList.push_back(std::make_pair<std::string,size_t>("Создать класс",TEMPLATE_TYPE_CLASS));
 TypeList.push_back(std::make_pair<std::string,size_t>("Создать класс MFC",TEMPLATE_TYPE_MFC_CLASS));
 TypeList.push_back(std::make_pair<std::string,size_t>("Создать класс MFC 'документ-вид'",TEMPLATE_TYPE_MFC_DV_CLASS));
 TypeList.push_back(std::make_pair<std::string,size_t>("Создать интерфейс",TEMPLATE_TYPE_INTERFACE));
}

void CMainWindow::on_CPushButton_Create_clicked()
{
 std::string prefix;
 std::string low_prefix;
 std::string template_name_h;
 std::string template_name_cpp;
 int type=ui->CComboBox_Type->currentIndex();
 if (type==TEMPLATE_TYPE_CLASS)
 {
  template_name_h="./Template/class.h.txt";
  template_name_cpp="./Template/class.cpp.txt";
   prefix="C";
   low_prefix="c";
  }
  if (type==TEMPLATE_TYPE_MFC_CLASS)
  {
   template_name_h="./Template/mfc_class.h.txt";
   template_name_cpp="./Template/mfc_class.cpp.txt";
   prefix="C";
   low_prefix="c";
  }
  if (type==TEMPLATE_TYPE_MFC_DV_CLASS)
  {
   template_name_h="./Template/mfc_dv_class.h.txt";
   template_name_cpp="./Template/mfc_dv_class.cpp.txt";
   prefix="C";
   low_prefix="c";
  }
  if (type==TEMPLATE_TYPE_INTERFACE)
  {
   template_name_h="./Template/interface.h.txt";
   template_name_cpp="./Template/interface.cpp.txt";
   prefix="I";
   low_prefix="i";
  }

  std::string name;
  std::string description;

  name=ui->CLineEdit_Name->text().toStdString();
  description=ui->CLineEdit_Description->text().toStdString();

  //создаём имя файла, имя класса и имя макроса в заголовочном файле
  std::string class_name(prefix);
  class_name+=name;

  std::string file_name(low_prefix);
  std::string define_name(prefix+"_");

  size_t length=name.length();
  for(size_t n=0;n<length;n++)
  {
   unsigned char symbol=name[n];
   unsigned char h_symbol=toupper(symbol);
   unsigned char l_symbol=tolower(symbol);
   if (symbol>='A' && symbol<='Z')
   {
    if (define_name.length()>2) define_name+="_";
   }
   define_name+=static_cast<char>(h_symbol);
   file_name+=static_cast<char>(l_symbol);
  }
  define_name+="_H";

  std::string header_file_name=file_name;
  header_file_name+=".h";
  std::string source_file_name=file_name;
  source_file_name+=".cpp";

  CreateOutputFile(name,file_name,class_name,define_name,description,template_name_h,header_file_name);
  CreateOutputFile(name,file_name,class_name,define_name,description,template_name_cpp,source_file_name);

}

void CreateOutputFile(std::string name,std::string file_name,std::string class_name,std::string define_name,std::string description,std::string tempate_file_name,std::string output_file_name)
{
 //список замен
 std::vector<std::pair<std::string,std::string> > change_list;//список замен
 change_list.push_back(std::make_pair("$CLASS_NAME$",class_name));
 change_list.push_back(std::make_pair("$DEFINE_NAME$",define_name));
 change_list.push_back(std::make_pair("$DESCRIPTION$",description));
 change_list.push_back(std::make_pair("$FILE_NAME$",file_name));
 //определим минимальную и максимальную длину заменяемой строки
 size_t min_size=0;
 size_t max_size=0;
 size_t change_list_size=change_list.size();
 for(size_t n=0;n<change_list_size;n++)
 {
  size_t length=change_list[n].first.length();
  if (n==0)
  {
   min_size=length;
   max_size=length;
  }
  if (min_size>length) min_size=length;
  if (max_size<length) max_size=length;
 }
 CRAIIFileIn file_in(tempate_file_name.c_str(),std::ios_base::in|std::ios_base::binary);
 CRAIIFileOut file_out(output_file_name.c_str(),std::ios_base::out|std::ios_base::binary);

 if (file_in.IsOpened()==false) return;
 if (file_out.IsOpened()==false) return;

 std::unique_ptr<char[]> buffer(new char[max_size+1]);
 buffer.get()[max_size]=0;
 size_t buffer_length=0;
 while(1)
 {
  //читаем символ
  char symbol;
  if (file_in.GetHandle().read(reinterpret_cast<char*>(&symbol),sizeof(char)*1).fail()==true) break;
  if (buffer_length==max_size)//символ из буфера готов к выходу
  {
   if (file_out.GetHandle().write(reinterpret_cast<char*>(buffer.get()+0),sizeof(char)*1).fail()==true) break;
  }
  //сдвигаем буфер и добавляем в конец символ
  for(size_t n=0;n<max_size-1;n++) buffer[n]=buffer[n+1];
  buffer[max_size-1]=symbol;
  if (buffer_length<max_size) buffer_length++;
  if (buffer_length>=min_size)
  {
   //ищем в списке замен
   size_t offset=max_size-buffer_length;
   for(size_t n=0;n<change_list_size;n++)
   {
    size_t length=change_list[n].first.length();
    if (length>buffer_length) continue;
    if (change_list[n].first.compare(buffer.get()+max_size-length)==0)//замена найдена
    {
     //сохраняем буфер до offset
     if (file_out.GetHandle().write(reinterpret_cast<char*>(buffer.get()+offset),sizeof(char)*(buffer_length-length)).fail()==true) break;
     if (file_out.GetHandle().write(reinterpret_cast<const char*>(change_list[n].second.c_str()),sizeof(char)*(change_list[n].second.length())).fail()==true) break;
     buffer_length=0;
     break;
    }
   }
  }
 }
 //дозаписываем буфер
 if (buffer_length>0)
 {
  if (file_out.GetHandle().write(reinterpret_cast<char*>(&buffer[max_size-buffer_length]),sizeof(char)*(buffer_length)).fail()==true) return;
 }
}

//====================================================================================================
//открытые функции класса
//====================================================================================================
