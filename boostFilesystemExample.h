/* NOTE:  
              LIBS +=   -lboost_filesystem -lboost_system
              
              http://www.boost.org/doc/libs/1_61_0/libs/filesystem/doc/reference.html#path-filename
              http://www.boost.org/doc/libs/1_61_0/libs/filesystem/example/simple_ls.cpp
*/

#define BOOST_FILESYSTEM_VERSION 3

//  As an example program, we don't want to use any deprecated features
#ifndef BOOST_FILESYSTEM_NO_DEPRECATED
#  define BOOST_FILESYSTEM_NO_DEPRECATED
#endif
#ifndef BOOST_SYSTEM_NO_DEPRECATED
#  define BOOST_SYSTEM_NO_DEPRECATED
#endif

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include <iostream>

namespace fs = boost::filesystem;

const char* chars_folder_ ;
bool getSubDIRfilenames(const char* chars_folder_, std::vector<std::string>& filename,
                                                   std::vector<std::string>& corfoldername)
    fs::path p(fs::current_path());
    if (chars_folder_)
        p = fs::system_complete(chars_folder_);
    else
        std::cout << "\nusage:   simple_ls [path]" << std::endl;

    unsigned long file_count = 0;
    unsigned long dir_count = 0;
    unsigned long other_count = 0;
    unsigned long err_count = 0;

    if (!fs::exists(p)){
        std::cout << "\nNot found: " << p << std::endl;
    }else
        return 0;

    if (fs::is_directory(p)){
        std::cout << "\nIn directory: " << p << "\n\n";
        fs::directory_iterator end_iter;
        for (fs::directory_iterator dir_itr(p);dir_itr != end_iter;++dir_itr){
            if (fs::is_directory(dir_itr->status())){
                std::string s = dir_itr->path().string();   // get the folder's path
                size_t found = s.find_first_not_of(chars_folder_);
                if (found != std::string::npos)
                   s.erase(s.begin(),s.begin() + found);
                 els
                   s.erase(s.begin(),s.begin()+ sizeof(chars_folder_));  // get th folder's name

                std::cout << s << " [directory]\n";
                fs::path subP = fs::system_complete(dir_itr);
                if(fs::is_directory(subP)){
                    fs::directory_iterator end_iter;
                    for(fs::directory_iterator dir_itr(subP);
                                    dir_itr != end_iter;++dir_itr){
                        if(fs::is_regular_file(dir_itr->status())){
                            ++file_count;
                            std::string sFileName = dir_itr->path().string();    // get the filename
                            std::cout << sFileName << "\n";
                            filename.push_back(sFileName);
                            corfoldername.push_back(s);
                        }
                    }
                }else if(fs::is_regular_file(dir_itr->status())){
                    ++file_count;
                    std::cout << dir_itr->path().filename() << "\n";
                }else{
                    ++other_count;
                    std::cout << dir_itr->path().filename() << " [other]\n";
                }
                ++dir_count;
            }
        }
        std::cout << "\n" << file_count << " files\n"
              << dir_count << " directories\n"
              << other_count << " others\n"
              << err_count << " errors\n";
        return 1;
    }else{
        std::cout << "\nFound: " << p << "\n";
        return 0;
    }
}
void saveFolderName(std::vector<std::string> foldername, const std::string s = chars_folder_){
    std::ofstream fstrm(s + "foldername.txt", std::ofstream::out);
    if (!fstrm){
        std::cout << s <<" cannot be opened" << std::endl;
        return;
    }
    for(auto a : foldername)
        fstrm << "'" << a << "'" << ',';
    fstrm.close();

}
