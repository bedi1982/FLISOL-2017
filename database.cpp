#include "database.h"

#include "QSqlDatabase"
#include "QSqlError"
#include "QMessageBox"

using namespace std;

Database::Database(){
    //objeto de database sendo criado
}

bool Database::Connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Teste");
    db.setUserName("root");
    //BEWARE CHANGING THIS CLASS NEEDS THE CLIENT TO FIX THE PASSWORD//
    //db.setPassword("xxxxxxx");
    if(db.open()){
        return true;
    }else{
        QMessageBox::critical(0, "Database Down", db.lastError().text());
        return false;
    }
}
