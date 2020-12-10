/* 
 hworld  
*/

#ifndef CONFIGURE_BASE_H_
#define CONFIGURE_BASE_H_

#include <json/json.h>
#include <utils/singleton.h>
#include <utils/strings.h>
#include <utils/net.h>

namespace hworld {

	class LoggerConfigure {
	public:
		LoggerConfigure();
		~LoggerConfigure();

		std::string path_;
		std::string dest_str_;
		std::string level_str_;
		int32_t time_capacity_;
		int64_t size_capacity_;

		uint32_t dest_;
		uint32_t level_;
		int32_t expire_days_;
		bool Load(const Json::Value &value);
	};

	class DbConfigure {
	public:
		DbConfigure();
		~DbConfigure();

		std::string keyvalue_db_path_;
		std::string ledger_db_path_;
		std::string account_db_path_;
		std::string rational_string_;
		std::string rational_db_type_;
		std::string tmp_path_;
		bool async_write_sql_;
		bool async_write_kv_;
		bool Load(const Json::Value &value);
	};

	class SSLConfigure {
	public:
		SSLConfigure();
		~SSLConfigure();

		std::string chain_file_;
		std::string private_key_file_;
		std::string private_password_;
		std::string dhparam_file_;
		std::string verify_file_;

		bool Load(const Json::Value &value);
	};

	class ConfigureBase  {
	public:
		ConfigureBase();
		~ConfigureBase();

	public:

		virtual bool Load(const std::string &config_file_path);
		virtual bool LoadFromJson(const Json::Value &value) { return false; };

		static void GetValue(const Json::Value &object, const std::string &key, std::string &value);
		static void GetValue(const Json::Value &object, const std::string &key, int32_t &value);
		static void GetValue(const Json::Value &object, const std::string &key, uint32_t &value);
		static void GetValue(const Json::Value &object, const std::string &key, int64_t &value);
		static void GetValue(const Json::Value &object, const std::string &key, utils::StringList &list);
		static void GetValue(const Json::Value &object, const std::string &key, bool &value);
	};
}

#endif