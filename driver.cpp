// Jesus Perez
// Kristiine Laranjo
// Samba Diallo
// Dario Molina

//******************************************
/*
    The first sample is steel and falls in below 16000N.
    The second same is graphite and it also falls below 16000N.
    With this type of information we can conclude that all of our coupon samples did not fall
    within three standard deviations.Therefore, they fail the design factor of three standard deviations.
    
*/

//******************************************



#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
/*
precondition : takes in array.
postcondition: function will calculate the mean of values being read from data file.
Summary: returns the mean.
*/
double mean(vector<double>v);// mean will have to return a double so we can pass it in into variance without a problem.
/*
Precondition: Takes in a vector of type double
Postcondition: Returns the max in that vector
Summary: Prints the max of a vector to the screen
*/
void max(vector<double> v);// can be a void because we just want a max.
/*
Precondition: Takes in a vector of type double
Postcondition: Returns the minimum in that vector
Summary: Prints the minimum value of a vector to the screen
*/

double minimum(vector <double> v);// can be a void because we just want a max.
/*
Precondition: Takes in a vector of type double.
Postcondition: calculates the variance.
Summary: returns the variance.
*/

double variance( vector<double> vec, double meanz);// returns double so we can then use with standard deviation.
/*
Precondition: Takes in a vector of type double
Postcondition: calculates the standard deviation
Summary: returns the standard deviation.
*/

double stdrd(vector<double> vec, double var);// will return the standard deviation


int main()
{
    vector<double> name;
    vector<double>name2;
   
    double num, num2;
    double a = 0, b = 0;
    double c = 0, d = 0;
    double e = 0, f = 0;
    
    
    ifstream fin, fin2;
    fin.open("data.txt");
    fin2.open("data2.txt");
    
    while(fin >> num)
    {
       name.push_back(num);
        
    }
    cout.setf(ios::left);
    cout << setw(15) << "The mean of data.txt is: "<< setw(10) << mean(name) << endl;
    a = mean(name);
    max(name);
    cout << setw(15) << "The minimum of data2.txt is: " << setw(10) << minimum(name) << endl;
    
    c = variance(name, a);
    cout << setw(15) << "Variance is: "<< c << setw(10) << endl;
    cout << setw(15) << "Standard Deviation is: " << stdrd(name, c) << setw(10) << endl;
    
    fin.close();
    
    
    while(fin2 >> num2)
    {
       name2.push_back(num2);
        
    }
    cout << setw(15) << "The mean of data2.txt is: "<< setw(10) << mean(name2) << endl;
    b = mean(name2);
    max(name2);
    cout << setw(15) << "The minimum of data2.txt is: " << setw(10) << minimum(name2) << endl;
    
    d = variance(name2, b);
    cout << setw(15) << "Variance is: "<< d << setw(10) << endl;
    cout << setw(15) << "Standard Deviation is: " << stdrd(name2, d) << setw(10) << endl;
    
     e = stdrd(name, c);
    f = stdrd(name2, d);
    cout<< "TESTS :";
    cout << e*3 ;
    cout <<"\t" << f*3 << endl;
    
    fin2.close();

return 0;
}
double mean(vector<double>v)
{
    double result;
    double sum = 0, mean = 0;
    
    double size = v.size();
    
    
    
    for(int i = 0; i< size; i++)
    {
  
        sum = sum + v[i];
    }
  mean = (sum/size);   
    return mean;
}
void max(vector<double> v)// done K
{
    double max;
    max = v[0];
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i] > max)
            max = v[i];
    }
    
    cout <<setw(15)<< "The maximum value is: "<< setw(7) << max << endl;
    
}

double minimum( vector<double>v)// done D
{
  double min = 9999999, result;
  
  for( int i = 0; i < v.size(); i++)
  {
    if( v[i] < min)
      {
        min = v[i];
      
      }
  }
  
 return min;
}
double variance( vector<double> vec, double meanz){//going over
    double stored = 0, total = 0, y = 0, sum = 0;
    double num_val = vec.size();
    //cout << num_val << endl;
    
    y= meanz;
    
    
    for(int i = 0; i < num_val; i++){
       stored = pow((vec[i] - y), 2);
        sum = sum + stored;
       }
        
    total = (sum / num_val);
    return total;
}

double stdrd(vector<double> vec, double var){
double sum = 0, total = 0, y;
y = var;
total = sqrt(y);

return total;
}






