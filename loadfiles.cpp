//Auxiliary module for loading files in the Meridian pattern recognition system
#include <iostream>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

/* using namespace boost::filesystem;
namespace fs = boost::filesystem; */

const String keys =
{
   "{help h  |      | print this message   }"
   "{run r   |      | ok run               }"
   "{load    |.     | path load for file  }"
   "{save    |.     | path save for file  }"
   "{N count |100   | count of objects     }"
};


int CopyDirHigh(string src, string dest) //копирование файлов или каталогов через системную команду cp cp -R catalog1/. catalog2
{
string cmd = "cp -R "+src+dest;
//convert string to char[]
int n = cmd.length();
char cmdchar[n+1];
strcpy(cmdchar,cmd.c_str());
try
 {
	system(cmdchar); //-R recursiv
   }
catch(const char* msg)
 {
	cout << "Error Copy files! \n" <<endl;
	cout << msg <<endl;
   }
return 0;
}

int main(int argc, const char** argv)
{
	Mat frame;
	CommandLineParser parser(argc, argv, keys); //  ./loadfiles -load="catalog1" -save="catalog2"

if (parser.has("help"))  //./loadfiles - help
{
    parser.about("Application LoadFile v1.0");
    parser.printMessage();
    return 0;
}


if (parser.has("run"))  //./loadfiles - run
{
    for(int i=1;i<argc;i++)
    {
	 cout << argv[i]<<endl;
     cout << "\n"<<endl;
	}

	//fs::copy("/testdir1", "/testdir2");
	/* For Testing...
	try {
			fs::copy_file("/testdir1", "/testdir2");
		}
    catch(fs::filesystem_error& ex)
     {
			std::cout << "Could not copy /testdir1 /testdir2 " << ex.what() << '\n';
	 }
	 */
    return 0;
}

String src_path = parser.get<String>("load");
cout << src_path << endl;

String dst_path = parser.get<String>("save");
cout << dst_path << endl;

if (!parser.check())
{
    parser.printErrors();
    return 0;
}


//frame = imread("./"+load_path);
//imwrite("./"+save_path,frame);

src_path = parser.get<String>("load")+"/. "; //!!! cp -R catalog1/. catalog2
dst_path = "./"+parser.get<String>("save");
cout << src_path << endl;
cout << dst_path << endl;
CopyDirHigh(src_path, dst_path);


cout << "Close programm - ok! \n" <<endl;

return(0);
}
