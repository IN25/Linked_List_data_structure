#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stats
{
private:
    vector<T> _data;

public:
    Stats(const T data[], const int &size);

    void add(const T value);
    double average() const;

    T min() const;
    T max() const;

    void print() const;
};


template <typename T>
Stats<T>::Stats(const T data[], const int &size)
{
    for (int i = 0; i < size; i++)
    {
        _data.push_back(data[i]);
    }
}

template <typename T>
void Stats<T>::add(const T value)
{
    _data.push_back(value);
}

template <typename T>
double Stats<T>::average() const
{
    double sum;
    double size = (double)_data.size();
    double average;

    for (double i : _data)
    {
        sum += i;
    }

    average = sum / size;
    return average;
}

template <typename T>
T Stats<T>::min() const
{
    T min_value = _data[0];

    for (T i : _data)
    {
        if (i < min_value)
        {
            min_value = i;
        }
    }
    return min_value;
}

template <typename T>
T Stats<T>::max() const
{
    T max_value = _data[0];

    for (T i : _data)
    {
        if (i > max_value)
        {
            max_value = i;
        }
    }
    return max_value;
}

int main()
{
    //short
    cout << "short" << endl;
    Stats<short> s1 = Stats<short>((const short[]){1, 2, 3, 4, 5}, 5);

    s1.add(6);

    cout << "shorts average: " << s1.average() << endl;
    cout << "shorts min: " << s1.min() << endl;
    cout << "shorts max: " << s1.max() << "\n\n";


    //int
    cout << "int" << endl;
    Stats<int> s2 = Stats<int>((const int[]){1, 2, 3, 4, 5}, 5);

    s2.add(6);

    cout << "int average: " << s2.average() << endl;
    cout << "int min: " << s2.min() << endl;
    cout << "int max: " << s2.max() << "\n\n";


    //double
    cout << "double" << endl;
    Stats<double> s3 = Stats<double>((const double[]){1.1, 2.2, 3.3, 4.4, 5.5}, 5);

    s3.add(6.6);

    cout << "double average: " << s3.average() << endl;
    cout << "double min: " << s3.min() << endl;
    cout << "double max: " << s3.max() << "\n\n";

    return 0;
}