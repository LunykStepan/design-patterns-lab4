#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cctype>

using namespace std;

void task1(const vector<int>& nums) {
    cout << "1. Odd numbers: ";
    for_each(nums.begin(), nums.end(), [](int x) {
        if (x % 2 != 0) cout << x << " ";
        });
    cout << endl;
}

void task2(const vector<double>& nums) {
    double sum = accumulate(nums.begin(), nums.end(), 0.0);
    double avg = nums.empty() ? 0 : sum / nums.size();
    cout << "2. Average value: " << avg << endl;
}

void task3(vector<string> strs) {
    sort(strs.begin(), strs.end(), [](string a, string b) {
        return a < b;
        });

    cout << "3. Alphabetical sorting: ";
    for (auto& s : strs) cout << s << " ";
    cout << endl;
}

void task4(const vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0,
        [](int acc, int x) {
            return (x % 2 == 0) ? acc + x : acc;
        });

    cout << "4. Sum of even numbers: " << sum << endl;
}

void task5(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = [](int a, int b) { return a * b; }(result, i);
    }
    cout << "5. Factorial(" << n << "): " << result << endl;
}

void task6(const vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int product = accumulate(nums.begin(), nums.end(), 1,
        [](int a, int b) { return a * b; });

    cout << "6. Sum: " << sum << ", Product: " << product << endl;
}

void task7(const vector<int>& nums) {
    vector<int> result(nums.size());

    transform(nums.begin(), nums.end(), result.begin(),
        [](int x) { return x * x; });

    cout << "7. Squares: ";
    for (int x : result) cout << x << " ";
    cout << endl;
}

void task8(vector<string> strs) {
    sort(strs.begin(), strs.end(),
        [](string a, string b) {
            return a.size() < b.size();
        });

    cout << "8. Sorting by length: ";
    for (auto& s : strs) cout << s << " ";
    cout << endl;
}

void task9(const string& sentence) {
    int count = 0;
    bool inWord = false;

    for_each(sentence.begin(), sentence.end(), [&](char c) {
        if (c != ' ' && !inWord) {
            count++;
            inWord = true;
        }
        else if (c == ' ') {
            inWord = false;
        }
        });

    cout << "9. Word count: " << count << endl;
}

void task10(const vector<string>& strs) {
    auto it = find_if(strs.begin(), strs.end(),
        [](const string& s) {
            return !s.empty();
        });

    cout << "10. First non-empty string: ";
    if (it != strs.end()) cout << *it;
    else cout << "none";
    cout << endl;
}

void task11(const vector<string>& strs) {
    bool result = all_of(strs.begin(), strs.end(),
        [](const string& s) {
            return !s.empty() && isupper(s[0]);
        });

    cout << "11. All start with uppercase: "
        << (result ? "Yes" : "No") << endl;
}

void task12(vector<int> nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    cout << "12. Second largest number: ";
    if (nums.size() >= 2) cout << nums[1];
    else cout << "none";
    cout << endl;
}

void task13(const vector<int>& nums) {
    vector<int> evens;

    copy_if(nums.begin(), nums.end(), back_inserter(evens),
        [](int x) { return x % 2 == 0; });

    cout << "13. Largest even number: ";
    if (!evens.empty())
        cout << *max_element(evens.begin(), evens.end());
    else
        cout << "none";

    cout << endl;
}

int main() {

    vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    vector<double> doubles = { 1.5, 2.5, 3.0 };
    vector<string> strings = { "banana", "apple", "pear", "" };

    task1(nums);
    task2(doubles);
    task3(strings);
    task4(nums);
    task5(5);
    task6(nums);
    task7(nums);
    task8(strings);
    task9("Hello world from C++");
    task10(strings);
    task11({ "Apple", "Banana", "Cherry" });
    task12(nums);
    task13(nums);

    return 0;
}