#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 5;
const int COURSE_COUNT = 3;

// Function prototypes
void calculateStudent(int i, string NameArr[], double Score[][3], double &total, double &average);
void displayAll(int n, string NameArr[], double Score[][3]);
int findTopStudent(int n, string NameArr[], double Score[][3]);

int main()
{
    // Test data stored directly in main()
    int n = 3;
    string NameArr[MAX] = {"Alice", "Bob", "Carl"};
    double Score[MAX][3] = {
        {90, 85, 95},
        {70, 80, 75},
        {88, 92, 84}
    };

    cout << fixed << setprecision(2);
    cout << "=== Student Grade Report ===" << endl;
    displayAll(n, NameArr, Score);
    cout << endl;

int topStudentIndex = findTopStudent(n, NameArr, Score);
    double total, average;
    calculateStudent(topStudentIndex, NameArr, Score, total, average);
    cout << "Top student: " << NameArr[topStudentIndex]
         << " (Total: " << total << ", Average: " << average << ")" << endl;

    return 0;
}

// Calculate total and average for one student
void calculateStudent(int i, string NameArr[], double Score[][3], double &total, double &average)
{
    total = 0;
    for (int j = 0; j < COURSE_COUNT; j++)
    {
        total += Score[i][j];
    }
    average = total / COURSE_COUNT;
}

void displayAll(int n, string NameArr[], double Score[][3])
{
    for (int i = 0; i < n; i++)
    {
        double total, average;
        calculateStudent(i, NameArr, Score, total, average);
        cout << NameArr[i] << ": ";
        for (int j = 0; j < COURSE_COUNT; j++)
        {
            cout << Score[i][j] << " ";
        }
        cout << "Total: " << total << ", Average: " << average << endl;
    }
}

// Find the index of the student with the highest total score
int findTopStudent(int n, string NameArr[], double Score[][3])
{
    int topIndex = 0;
    double topTotal = -1.0;

    for (int i = 0; i < n; i++)
    {
        double total, average;
        calculateStudent(i, NameArr, Score, total, average);

        if (total > topTotal)
        {
            topTotal = total;
            topIndex = i;
        }
    }

    return topIndex;
}