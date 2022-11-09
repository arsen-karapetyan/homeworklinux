#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <cerrno>
#include <sstream>
#include <cstring>

int main() {
 int count;
 std::cout << "Please enter the number of files: " << std::endl;
 std::cin >> count;
 
 if (count < 0){
  return -1;
 }

 for (int i = 1; i < count+1; ++i) {
  std::string file = "file_";
  std::string text = "Hello World ";
  file+=(std::to_string(i));
  file+=(".txt");
  text+=(std::to_string(i));
  
  int fd = open(file.c_str(), O_WRONLY | O_CREAT, S_IRWXU);
  
  if(fd < 0) {
 return errno;
 }
 
  write(fd, text.c_str(),text.size());
  close(fd);
 }
}
