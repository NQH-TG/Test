#include <iostream>
#include <ostream>
#include <array>
#include <string>
#include <fstream>

struct Students {
   char name[50];
   unsigned int id;
   float score;
};

void swap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}

void addStudent(Students& s) {
    std::ofstream myfile;
    myfile.open("/Users/louisnguyen/Desktop/Work/Test/Test/Base.lproj/Output.txt");
    std::cout << "Enter the name without space: \n";
    std::cin >> s.name;
    std::cout << "Enter the ID: \n";
    std::cin >> s.id;
    std::cout << "Enter the Score: \n";
    std::cin >> s.score;
    myfile << s.name << "\n";
    myfile << s.id << "\n";
    myfile << s.score << "\n";
    myfile.close();
}

float partition(float arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
        
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
            
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            
        }
    }
    return pivotIndex;
    
}

//Sort Ascending
void SortAsc(float arr[], int start, int end) {
    if (start >= end)
        return;
    float p = partition(arr, start, end);
    SortAsc(arr, start, p - 1);
    SortAsc(arr, p + 1, end);
    
}

//Sort Descending
void SortDesc(float arr[], int start, int end) {
    if (start >= end)
        return;
    float p = partition(arr, start, end);
    SortDesc(arr, start, p - 1);
    SortDesc(arr, p + 1, end);
    for (int i = 0; i < end; i++) {
        swap(arr[i], arr[end - i]);
        if (i > end / 2 - 1) {
            break;
        }
    }
}

//Print Array
void printArr(float a[], int n){
   for(int i = 0; i < n; i++) {
      std::cout << " " << a[i];
   }
}

//Random Students
void randomStudents() {
    std::string Name[20] = {"Nguyen Hung", "Huynh Giang", "Nguyen Dung", "Pham Hong", "To Quyen", "Nguyen Trang", "Dang Thuan", "Bich Nha", "Nguyen Nam", "Quoc Tuan", "Huynh Trung", "Tuan Dat", "Le Dinh", "Nhiet Ba", "Ly Nha", "Ngoc Trinh", "Le Bong", "Ngoc Nhu", "Thanh Nhi", "Pham Bang"};
    for (int i = 0; i < 10; i++) {
        std::cout << Name[rand() % 20] << "\n";
        std::cout << rand() % 10000 << "\n";
        std::cout << rand() % 10 << "\n";
    }
}

int main() {
    const int n = 10;
    std::cout << "Student Information\n";
    std::cout << "Enter theese options below:\n";
    std::cout << "a to print 10 students' information randomly.\n";
    std::cout << "i to insert 10 students' information.\n";
    std::cout << "d to sort descending test scores.\n";
    std::cout << "c to sort ascending test cores.\n";
    std::cout << "p to export a html file.\n";
    std::cout << "e to stop the program.\n";
    
    //list
    float list[10] = {1, 5, 7, 9, 10, 4, 3, 2, 6, 8};
    
    //Option
    char name_option;
    std::cin >> name_option;
    switch(name_option) {
        case 'a' :
            randomStudents();
            std::cout << "Continuous.................\n";
            return main();
        case 'i' :
            std::cout << "Please enter 10 students' information: \n";
            std::array<Students, n> Students;
            for(int i = 0; i < n; i++) {
                addStudent(Students[i]);
            }
            std::cout << "Continuous.................\n";
            return main();
        case 'd' :
            SortDesc(list, 0, n - 1);
            printArr(list, n);
            std::cout << "\nContinuous.................\n";
            return main();
        case 'c' :
            SortAsc(list, 0, n - 1);
            printArr(list, n);
            std::cout << "\nContinuous.................\n";
            return main();
        case 'e' :
            printf("End.\n");
            break;
        case 'p' :
            std::string link = "open ~/Desktop/Work/Test/Test/Page.html";
            system(link.c_str());
            std::cin.get();
            break;
    }
    
    return 0;
}


