#include <iostream>
#include <chrono>
    using namespace std;

    int main()
    {
        int a[100];
        int minval = 99;
        int maxval = -99;
        cout << "1) Array: ";
        for (int i = 0; i < 100; i++) {
            a[i] = rand() % 198 - 99;
            cout << a[i] << " ";
        }

        cout << "\n\n2) Sorted array: ";
        auto start = chrono::system_clock::now();
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 99; j++) {
                if (a[j] < a[j + 1])
                    swap(a[j], a[j + 1]);
            }

        }
        for (int i = 0; i < 100; i++) {
            cout << a[i] << " ";
        }
        auto endtime = chrono::system_clock::now();

        chrono::duration<double> elapsed = endtime - start;
        cout << "\n\nElapsed time for sorting: " << elapsed.count() << " s";

        for (int i = 0; i < 100; i++) {
            if (maxval < a[i])
                maxval = a[i];
            if (minval > a[i])
                minval = a[i];
        }
        cout << "\n\n3) Max and min array elements: " << "\n Max: " << maxval << "\n Min: " << minval << endl;

        int countval = 0;
        int avgval = (minval + maxval) / 2;

        cout << "\n" << "4) Average: " << avgval << "\n";

        for (int i = 0; i < 100; i++) {
            if (avgval == a[i]) {
                countval++;
                cout << "\nEqual to average indices: " << i << "\n";
            }
        }
        cout << "\nIts quantity: " << countval << "\n";

        int A, B, cnt = 0;
        cout << "\n5) Enter A: ";
        cin >> A;
        for (int i = 0; i < 100; i++)
            if (a[i] < A)
                cnt++;
        cout << "Quantity of numbers which smaller than A: " << cnt;

        cout << "\n\n6) Enter B: ";
        cin >> B;
        for (int i = 0; i < 100; i++)
            if (a[i] > B)
                cnt++;
        cout << "Quantity of numbers which bigger than B: " << cnt;

        //    auto start = chrono::system_clock::now();
        int i1, i2;
        cout << "\n\n8) Enter two array indices:";
        cin >> i1 >> i2;
        if ((i1 >= 0 && i1 <= 99) && (i2 >= 0 && i2 <= 99)) {
            cout << "\nChanged array: ";
            for (int i = 0; i < 100; i++) {
                if (i == i1)
                    swap(a[i], a[i1]);
                break;
            }

            for (int i = 0; i < 100; i++) {
                if (i == i2)
                    swap(a[i], a[i2]);
                break;
            }

            for (int i = 0; i < 100; i++) {
                swap(a[i1], a[i2]);
                break;

            }
            for (int i = 1; i < 100; i++) {
                cout << a[i] << " ";
            }
        }
        else
            cout << "\nWrong symbol\n";


        return 0;
    }



