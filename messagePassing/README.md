Lambda Functions in C++ – Short Notes & Tips 🚀
1️⃣ What is a Lambda Function?
A lambda function (also called an anonymous function) is a short, inline function that can be defined inside another function or block of code.

✅ Syntax:

 
[capture_list] (parameters) -> return_type { function_body };
Example:

 
auto add = [](int a, int b) -> int { return a + b; };
cout << add(5, 3);  // Output: 8
2️⃣ Why are Lambda Functions Important?
✔ Short & Readable – No need for long function definitions.
✔ Encapsulation – Keeps logic inside the function that uses it.
✔ Useful for Functional Programming – Works well with STL functions (std::sort, std::for_each).
✔ Supports Captures ([this], [&], [=]) – Can access local or class variables.
✔ Multi-threading – Used in condition variables and thread synchronization.

3️⃣ Where to Use Lambda Functions?
Use Case	Example
STL Algorithms	std::sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
Multithreading (Condition Variable)	cv.wait(lock, [this] { return secondCheck; });
Event Handling	button.onClick([] { cout << "Clicked!"; });
Custom Comparators	std::priority_queue<int, vector<int>, decltype(compare)> pq(compare);
Callbacks	std::function<void(int)> f = [](int x) { cout << x; };
4️⃣ Lambda Function Capture Modes
Capture Mode	Syntax	Meaning
No Capture	[] { return 42; }	Cannot access external variables
Capture by Value	[=] { return x + y; }	Copies external variables inside lambda
Capture by Reference	[&] { x++; }	Modifies external variables directly
Capture this	[this] { return this->x; }	Accesses class members
Mixed Capture	[=, &y] { return x + y; }	Captures x by value, y by reference
5️⃣ Examples of Lambda Usage
📌 Example 1: Sorting Using Lambda
cpp
Copy
Edit
vector<int> v = {5, 2, 9, 1};
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });  // Sort in descending order
📌 Example 2: Using std::for_each
cpp
Copy
Edit
vector<int> v = {1, 2, 3};
for_each(v.begin(), v.end(), [](int x) { cout << x << " "; }); // Output: 1 2 3
📌 Example 3: Using Lambdas in Threads
cpp
Copy
Edit
thread t([] { cout << "Hello from thread!\n"; });
t.join();
6️⃣ When NOT to Use Lambda Functions?
🚫 When the function is large & complex – Use a separate function instead.
🚫 When the function needs to be reused multiple times – Define a named function.
🚫 When it reduces code readability – Sometimes, lambdas can be confusing in complex logic.

🎯 Quick Recap
✅ Lambda functions are useful for short, inline operations.
✅ Capture lists ([=], [&], [this]) allow accessing external variables.
✅ Used in STL, multithreading, and callbacks for cleaner, more efficient code.
✅ Use carefully when the logic is complex or needs to be reused.