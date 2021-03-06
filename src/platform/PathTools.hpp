// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <string>

namespace platform {
std::string getDefaultDataDirectory(const std::string & cryptonote_name); // we avoid including app-specific headers into our platform code
// Old method
// Windows < Vista: C:\Documents and Settings\Username\Application Data\CRYPTONOTE_NAME
// Windows >= Vista: C:\Users\Username\AppData\Roaming\CRYPTONOTE_NAME
// Mac: ~/.CRYPTONOTE_NAME
// Unix: ~/.CRYPTONOTE_NAME
// Storing 40Gb in directory hidden from user (.bytecoin) is generally bad idea
// Storing 40Gb in Roaming user profile was bad idea for corporate Windows users (should be in Local)

// New method
// Windows < Vista: C:\Documents and Settings\Username\Application Data/<app_name>
// Windows >= Vista: C:\Users\Username\AppData\Local/<app_name>
// Mac: fullpath of ~/Library/Application Support/<app_name>
// Unix: fullpath of ~/.<app_name>
std::string get_app_data_folder(const std::string & app_name);

//  std::string getDefaultCacheFile(const std::string& dataDir);
std::string get_os_version_string();
bool create_directories_if_necessary(const std::string &path);
bool atomic_replace_file(const std::string &replacement_name, const std::string &old_file_name);
//  bool directoryExists(const std::string& path);
}
