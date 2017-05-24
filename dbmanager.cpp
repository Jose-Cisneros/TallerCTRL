#include "dbmanager.h"


DBManager::DBManager(const QString &path)
{

   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (m_db.open())
   {
      qDebug() << "Database: connection ok";
   }
   else
   {

      qDebug() << "Error: connection with database fail";
   }

}
