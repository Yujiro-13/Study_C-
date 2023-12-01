#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;

// 関数のプロトタイプ宣言
double evaluateExpression(const string& expression);
double applyOperator(double a, double b, char op);

int main() {
    string expression;

    cout << "数式を入力してください: ";
    getline(cin, expression);

    try {
        double result = evaluateExpression(expression);
        cout << "結果: " << result << endl;
    } catch (const exception& e) {
        cout << "エラー: " << e.what() << endl;
        return 1; // エラーコード1でプログラム終了
    }

    return 0; // 正常終了
}

// 数式の評価
double evaluateExpression(const string& expression) {
    istringstream iss(expression);
    stack<double> values;
    stack<char> operators;

    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            double value = stod(token);
            values.push(value);
        } else if (token == "(") {
            operators.push('(');
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperator(a, b, op));
            }
            operators.pop(); // '(' を取り除く
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!operators.empty() && operators.top() != '(' && (token == "*" || token == "/" || operators.top() == '+' || operators.top() == '-')) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperator(a, b, op));
            }
            operators.push(token[0]);
        } else {
            throw runtime_error("無効なトークン: " + token);
        }
    }

    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperator(a, b, op));
    }

    return values.top();
}

// 演算の適用
double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                throw runtime_error("ゼロで割り算はできません");
            }
        default:
            throw runtime_error("無効な演算子: " + op);
    }
}
