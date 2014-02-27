/*
Code: Trajectory Analyzer
Sachin Krishnan TV (sachin@physics.iitm.ac.in)

Remark:
27 Feb 2014: Prints the first few lines of a lammps trajectory file. 

TODO: Add more functions
	* splitting the trajectory file
	* perform RDF analysis

*/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

std::streampos fileSize( const char* filePath ){

    std::streampos fsize = 0;
    std::ifstream file( filePath, std::ios::in );

    fsize = file.tellg();
    file.seekg( 0, std::ios::end );
    fsize = file.tellg() - fsize;
    file.close();

    return fsize;
}

void doit(char *inpfile)
{
	char tchar[2]="#";
	int step=0;
	int tpos=-1;
	int i;
	bool first_step=true;
	bool second_step=false;

	double ulSize=fileSize(inpfile); 
	
	/*
		Variables to store essential info
	*/
	int first_timestep=0;
	int last_timestep=0;
	int dump_frequency=0;
	int number_of_atoms=0;
	vector <string> atom_info;
	
	double xlo,xhi,ylo,yhi,zlo,zhi;

	string temp;
	string junk, junk1;
	fstream fp;
	fp.open(inpfile);
	if(fp.bad()) cout<<"Error opening the file."<<endl;
	cout<<"Input file :"<<inpfile<<endl;

	while(!fp.eof())
	{
		fp>>temp;
		if(strcmp(temp.c_str(),"ITEM:")==0)
		{
			fp>>temp;		
			if(strcmp(temp.c_str(),"TIMESTEP")==0)
			{
				fp>>step;
				if(first_step)
					first_timestep=step;
				if(second_step)
				{
					dump_frequency=step-first_timestep;
					second_step=false;
					fp.seekg(ulSize-(number_of_atoms*(int)atom_info.size()*sizeof(double)),std::ios::beg);
				}
			}
			else if(strcmp(temp.c_str(),"NUMBER")==0 && first_step)
			{
				fp>>junk>>junk;
				fp>>number_of_atoms;	
			}else if(strcmp(temp.c_str(),"BOX")==0 && first_step)
			{
				fp>>junk>>junk>>junk>>junk;
				fp>>xlo>>xhi>>ylo>>yhi>>zlo>>zhi;
			}
			else if(strcmp(temp.c_str(),"ATOMS")==0 && first_step)
			{
				while(tchar[0]!='\n')
				{
					fp.get(tchar[0]);
					if(tchar[0]==' ')
					{
						atom_info.push_back(tchar);
						tpos++;
						continue;
					}
					atom_info[tpos].append(tchar);
				}	
				second_step=true;
				first_step=false;
			}
		}
	}
	last_timestep=step;
	cout<<"First Timestep:"<<first_timestep<<endl;
	cout<<"Last Timestep:"<<last_timestep<<endl;
	cout<<"Dump Frequency:"<<dump_frequency<<endl;
	cout<<"X Bounds:"<<xlo<<" "<<xhi<<endl;
	cout<<"Y Bounds:"<<ylo<<" "<<yhi<<endl;
	cout<<"Z Bounds:"<<zlo<<" "<<zhi<<endl;
	cout<<"Number of atoms:"<<number_of_atoms<<endl;
	cout<<"Atom info:";
	for(i=0;i<(int)atom_info.size();i++)
		cout<<atom_info[i];
	cout<<endl;
	fp.close();
}

int main(int argc, char **argv)
{
	if(argc>=1)
		doit(argv[1]);
	else
		cout<<"Arguments: <input-file>"<<endl;
	return 0;
}
