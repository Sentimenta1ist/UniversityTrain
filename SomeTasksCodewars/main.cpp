#include <iostream>
#include <string>
#include <ciso646>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <regex>
using namespace std;

void outVector(vector<unsigned long long> a)
{
    for (unsigned long long i = 0; i < a.size(); ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
/*
string catMouse(string field, unsigned int jump)
{
    int mouse = -1;
    int cat = -1;
    int dog = -1;
    for(int i = 0; i < field.size();i++)
    {
        if(field[i] == 'D') dog = i;
        if(field[i] == 'C') cat = i;
        if(field[i] == 'm') mouse = i;
    }

    if(mouse == -1 || cat == -1 || dog == -1) return "boring without all three";
    if(cat < dog && dog < mouse || cat > dog && dog > mouse)
    {
        if (cat < dog)
        {
            if (cat + jump >= dog)return "Protected!";
        }
        else
        {
            if (cat - jump <= dog) return "Protected!";
        }
    }
    if(cat < mouse)
    {
        if(cat + jump >= mouse )return "Caught!";
    }
    else
    {
        if(cat - jump <= mouse || cat - jump > field.size())return "Caught!";
    }

    return "Escaped!";
}
*/

/*
long long div (long long n)
{
    long long sum=1, i ,end;
    end = sqrt(n);
    for (i=2; i<=end; i++)
    {
        if (n%i==0)
            sum += i + n/i;
    }
    if(n == end*end) sum -= end;


    return sum;
}

*/

/*string buddy(long long start, long long limit)
{
    long long sum = 0;
    long long k = 0;
    long long i;
    if(start%2 == 0) i = start;
    else i = start + 1;
    for(i; i <= limit; i+=2)
    {
        sum = div(i);
        if(sum > i && div(sum-1) == i + 1) return '(' + to_string(k) + ' ' + to_string(sum-1) + ')';
    }
    return "Nothing";
}*/
/*

string buddy(long long start, long long limit)
{
    auto summa = [] (auto x)
    {
        int count = 1;
        int end = sqrt(x);
        for(int i = 2; i <= end; i++)
        {
            if(x%i == 0) count += i + x/i;
        }
        if(x == end * end) count -= end;
        return count;
    };
    for(auto j = start; j < limit; j++)
    {
        auto x = summa(j);
        if(x > j && summa(x-1) == j +1)return '(' + to_string(j) + ' ' + to_string(x-1) + ')';
    }
    return "Nothing";
}
*//*
int fibo(int n) // 1.1.2.3.5.8.13
{
    int result = 1;
    int f2 = 1;
    int f1 = 1;

    for (int i = 3; i <= n; i++)
    {

        result = f1 + f2;
        f2 = f1;
        f1 = result;

    }
    return result;
}
int rec(int n, int k)
{
    n++;k++;
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

void lol()
{
    //vector<int> cubes;
    int temp = 0;
    int sum = 0;
    for(int i = 0; i < 1000; i++)
    {
        temp = i;
        sum += (i % 10)*(i % 10)*(i % 10);
        temp /= 10;
        sum += (temp % 10)*(temp % 10)*(temp % 10);
        temp /= 10;
        sum += temp*temp*temp;

        if(sum == i) cout << i << ' ';
        sum = 0;
    }
}

int ci(char x)
{
    return x - 48;
}

string isSumOfCubes(string &str)
{
    string result = "";
    int temp = 0;
    int res = 0;
    int sum_of_res = 0;
    for(int i = 0; i < str.size();i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            temp = ci(str[i]);
        }
    }
    return result + to_string(res) + ' ' + to_string(sum_of_res) +
}


string numberFormat(long long n)
{
    string temp = "";
    string res = "";
    temp += to_string(n);
    int count = -1;
    for(int i = temp.size()-1; i >= 0;i--)
    {
        if( temp[i] >= '0' && temp[i] <= '9') count++;
        if(count == 3)
        {
            res.insert(0,1,',');
            count = 0;
        }
        res.insert(0,1,temp[i]);
    }
    return res;        {
            n /= k;
            k++;
            n *=k;
            in = 1;
        }
        if(in == 0)
}

std::string numberFormat(long long n) {
    string res=regex_replace(to_string(n),regex(R"(([+-]?\d{1,3})(?=(\d{3})*$))"),R"($1,)");
    res.pop_back();
    return res;
}

bool func(string &s)
{
    for(int i = 0; i < s.size(); i++)
    {

    }

}

int trotter(int n)
{
    if(n == 0) return -1;
    string str = "";
    int k = 1;

    while(1)
    {
        str += to_string(n);
        if((str.find('0') != string::npos && str.find('1') != string::npos && str.find('2') != string::npos && str.find('3') != string::npos && str.find('4') != string::npos && str.find('5') != string::npos && str.find('6') != string::npos && str.find('7') != string::npos && str.find('8') != string::npos && str.find('9') != string::npos))return n;
        n /= k;
        k++;
        n*=k;
    }

}

*/
/*
int simple(int number)
{
    for ( int i = 2; i * i <= number; i++ )
    {
        if ( number % i == 0 )
        {
            return 0;
        }
    }
    return 1;
}

string decomp(int n)
{
    string res;
    vector<int> simples;
    vector<int> powers;
    int count = 0;
    int temp;
    for(int i = 2; i <= n; i++)
    {
        temp = i;
        if(simple(temp))
        {
            simples.push_back(temp);
            powers.push_back(1);
        }
        else
        {
            for(int j = 0; j < simples.size(); j++)
            {
                while(temp > 1)
                {
                    if(temp % simples[count] == 0)
                    {
                        temp /= simples[count];
                        powers[count]++;
                    }
                    else
                    {
                        count++;
                        continue;
                    }
                }

            }
        }
        count = 0;
    }
    for(int i = 0; i < simples.size();i++)
    {
        res += to_string(simples[i]);
        if(powers[i] > 1) res +=  '^' + to_string(powers[i]);
        if(i < simples.size() - 1)res += " * " ;
    }

    return res;
}

int** arr;
int n;
bool found = false;

void recurs(int i,int j, int glub)
{
    if(found) return;
    if( i < 0 || j < 0 || i > n - 1 || j > n - 1) return;
    if( arr[i][j] == -1) return;
    if( arr[i][j] == -2)  {
     found = true;
     return;
    }

    if( arr[i][j] != 0) return;

    arr[i][j] = glub;

    recurs(i + 1, j, glub + 1);
    recurs(i - 1, j, glub + 1);
    recurs(i, j + 1, glub + 1);
    recurs(i, j - 1, glub + 1);

}

void outputArray()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
           printf("%3i", arr[i][j]);
        }
        cout << endl;
    }
}

bool path_finder(string maze)
{
    string mazes = "";
    for(int i = 0; i < maze.size(); i++)
    {
        if(maze[i] != '\n')
        {
            mazes += maze[i];
        }
    }
    cout << mazes <<endl;
    n = sqrt(mazes.size());
    int count_mazes = -1;

    arr = new int*[n];
    for(int i = 0; i < n; ++i)
        arr[i] = new int[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
           if(mazes[++count_mazes] == '.') arr[i][j] = 0;
           else arr[i][j] = -1;
        }
    }

    arr[0][0] = -2;

    outputArray();


    recurs(n - 1, n - 1, 1);
    cout << endl << found << endl;

    outputArray();

    return found;
}
int res[3];
int* solveEq(int a[3][4])
{


    int det = (a[0][0]*a[1][1]*a[2][2])+(a[0][1]*a[1][2]*a[2][0])+(a[1][0]*a[2][1]*a[0][2])-(a[0][2]*a[1][1]*a[2][0])-(a[0][1]*a[1][0]*a[2][2])-(a[0][0]*a[1][2]*a[2][1]);
    int det1 = (a[0][3]*a[1][1]*a[2][2])+(a[0][1]*a[1][2]*a[2][3])+(a[1][3]*a[2][1]*a[0][2])-(a[0][2]*a[1][1]*a[2][3])-(a[0][1]*a[1][3]*a[2][2])-(a[0][3]*a[1][2]*a[2][1]);
    int det2 = (a[0][0]*a[1][3]*a[2][2])+(a[0][3]*a[1][2]*a[2][0])+(a[1][0]*a[2][3]*a[0][2])-(a[0][2]*a[1][3]*a[2][0])-(a[0][3]*a[1][0]*a[2][2])-(a[0][0]*a[1][2]*a[2][3]);
    int det3 = (a[0][0]*a[1][1]*a[2][3])+(a[0][1]*a[1][3]*a[2][0])+(a[1][0]*a[2][1]*a[0][3])-(a[0][3]*a[1][1]*a[2][0])-(a[0][1]*a[1][0]*a[2][3])-(a[0][0]*a[1][3]*a[2][1]);

    res[0] = det1/det;
    res[1] = det2/det;
    res[2] = det3/det;

    return res;


vector<int> deleteNth(vector<int> arr, int n)
{
    vector<int> result;
    int count_ofNum = 0;
    int count = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[j] == arr[i] && arr[j] != -1)
            {
                count_ofNum++;
            }
            if(count_ofNum>n && arr[j] == arr[i])
            {
                arr[j] = -1;
            }
        }
        count_ofNum = 0;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != -1){
            result.push_back(arr[i]);
        }
    }

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return result;
}

 */


/*vector<int> sortArray(vector<int> array)
{
    vector<int> a;
    vector<int> b = array;
    for(int i = 0; i < array.size();i++)
    {
        if(array[i] % 2 != 0) a.push_back(array[i]);
    }

    int n = a.size();
    int R = n - 1;
    while (R > 0)
    {
        int k = 0;
        for (int i = 0; i <= R - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int b = a[i];
                a[i] = a[i + 1];
                a[i + 1] = b;

                k = i;
            }
        }

        R = k;
    }
    int counter_a = 0;
    for(int i = 0; i < b.size();i++)
    {
        if(b[i] % 2 != 0)
        {
            b[i] = a[counter_a];
            counter_a++;
        }
    }

    for(int i = 0; i < b.size();i++)
    {
        cout << b[i] << ' ';
    }
   return b;
}*/

/*
int simple(int number)
{
    for ( int i = 2; i * i <= number; i++ )
    {
        if ( number % i == 0 )
            return 0;
    }
    return 1;
}
class WeirdPrimeGen
{
public:
    static long long countOnes(long long n)
    {
        vector<int> g;
        g.push_back(1);
        g.push_back(1);
        g.push_back(1);
        vector<int> a;
        a.push_back(7);
        a.push_back(8);
        for (int i = 3; i <= n; i++)
        {
            if( simple(i) && i != 3 )
            {
                g.push_back(i);
                g.push_back(3);
                a.push_back(a.back()+i);
                a.push_back(a.back()+3);
                continue;
            }
            g.push_back(1);
            a.push_back(a.back()+1);
        }


        outVector(a);



        return 1;
    };
    static long long maxPn(long long n)
    {
        return 1;
    };
    static int anOverAverage(long long n)
    {
        return 1;
    };
};

*/
/*
int simple(long long number)
{
    for ( long long i = 2; i * i <= number; i++ )
    {
        if ( number % i == 0 )
            return 0;
    }
    return 1;
}


static pair <long long, long long> gap(int g, long long m, long long n)
{
    static pair<long long, long long> result (0,0);
    int k  = 0;

    for(long long i = m; i <= n-g; i++){
        if(simple(i))
        {
            for (long long j = i+1; j <= i+1+g;j++)
            {
                k++;
                if(simple(j))
                {
                    break;
                }
            }
            if( k == g)
            {
                result.first = i;
                result.second = i+g;
                cout << result.first;
                cout << result.second;
                return result;
            }
            k = 0;

        }
    }
    return result;
}


typedef unsigned long long ull;
ull denomit ( ull a, ull b)
{
    ull max,min,i;
    if (a>b) { max=a; min=b;}
    else { max=b; min=a;}
    for (i = max; i <=min*max; i+=max)
    {
        if (i%min==0) break;
    }

    return i;
}

string convertFrac(vector<vector<ull>> &lst)
{
    string res = "";
    ull denom;
    vector<ull> denomitian;

    for(ull i = 0 ; i < lst.size();i++)
    {
        denomitian.push_back(lst[i][1]);
    }
    denom = denomitian[0];
    for(ull i = 0; i < denomitian.size()-1;i++)
    {
        denom = denomit(denom,denomitian[i + 1]);
    }
    for(int i = 0; i < lst.size(); i++)
    {
        res+= '(' + to_string(denom / lst[i][1]) + ',' + to_string(denom) + ')';
    }
    return res;
}*/

/*
string listSquared(long long m, long long n)
{
    long long temp;
    double temp1;
    string res = "[";
    long long sum = 0;
    for(long long i = m; i <= n ;i++){
        for(int j = 1; j <= i; j++){
            if(i%j == 0) sum+=j*j;
        }
        temp1 = sqrt(sum);
        temp = temp1;
        if(temp == temp1) res += "[" + to_string(i) + ", " +to_string(sum) + "], ";
        sum = 0;
    }
    if(res.size() > 1)res.erase(res.size()-2, 2);
    return res + ']';
}*/


string encrypt(string text, int n)
{
    string res;
    res = text;
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        for(int i = 0; i < text.size(); i++)
        {
            if(i % 2 != 0)
            {
                res[++index] = text[i];
            }
        }
        for(int i = 0; i < text.size(); i++)
        {
            if(i % 2 == 0)
            {
                res[++index] = text[i];
            }
        }
        index = -1;
        text = res;
    }

    return res;
}

string decrypt(string encryptedText, int n)
{
    string res;
    res = encryptedText;
    int index = 1;
    for(int i = 0; i < n; i++)
    {
        for(int i = 0; i < encryptedText.size() / 2; i++)
        {

            res[index] = encryptedText[i];
            index += 2;

        }
        index = 0;
        for(int i = encryptedText.size() / 2; i < encryptedText.size(); i++)
        {
            res[index] = encryptedText[i];
            index += 2;
        }
        index = 1;
        encryptedText = res;
    }

    return res;
}

int main()
{

    cout << decrypt("s eT ashi tist!", 2);

    return 0;
}





