#include <iostream>
#include <pqxx/pqxx>

int main() {
  std::cout << "Hello Fleet Management System!" << std::endl;

  const std::string db_host =
      std::getenv("DB_HOST") ? std::getenv("DB_HOST") : "localhost";
  const std::string db_port =
      std::getenv("DB_PORT") ? std::getenv("DB_PORT") : "5432";
  const std::string db_name =
      std::getenv("DB_NAME") ? std::getenv("DB_NAME") : "devdb";
  const std::string db_user =
      std::getenv("DB_USER") ? std::getenv("DB_USER") : "dev_user";
  const std::string db_password =
      std::getenv("DB_PASSWORD") ? std::getenv("DB_PASSWORD")
                                 : "dev_fleet_123";

  std::string con_ =
      "host=" + db_host + " port=" + db_port + " dbname=" + db_name +
      " user=" + db_user + " password=" + db_password;

  try {
    pqxx::connection conn(con_);

    if (conn.is_open()) {
      std::cout << "[INFO] Database connection established successfully."
                << std::endl;
    } else {
      std::cerr << "[ERROR] Failed to open DB Connection." << std::endl;
      return 1;
    }

    // Simple test query
    pqxx::work txn(conn);
    auto result = txn.exec("SELECT version();");
    txn.commit();

    std::cout << "[INFO] Postgres Version: " << result[0][0].c_str()
              << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "[ERROR] Exception during DB Connection: " << e.what()
              << std::endl;
    return 1;
  }

  return 0;
}