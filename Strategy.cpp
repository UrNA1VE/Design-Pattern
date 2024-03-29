#include<iostream>
#include<vector>

using namespace std;

class Strategy {
public:
    virtual ~Strategy() {}
    virtual string DoAlgorithm(const vector<std::string> &data) const = 0;
};

class Context {
private:
    Strategy *strategy_;
public:
    Context(Strategy *strategy = nullptr) : strategy_(strategy) {
    }
    ~Context() {
        delete this->strategy_;
    }

    void set_strategy(Strategy *strategy) {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    void DoSomeBusinessLogic() const {
   
        cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
        string result = this->strategy_->DoAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
        cout << result << "\n";

    }
};

class ConcreteStrategyA : public Strategy {
public:
    string DoAlgorithm(const vector<string> &data) const override {
        string result;
        for_each(begin(data), end(data), [&result](const string &letter) {
            result += letter;
        });
        sort(begin(result), end(result));

        return result;
    }
};
class ConcreteStrategyB : public Strategy {
    string DoAlgorithm(const vector<std::string> &data) const override
    {
        string result;
        for_each(begin(data), end(data), [&result](const string &letter) {
            result += letter;
        });
        sort(begin(result), end(result));
        for (int i = 0; i < result.size() / 2; i++) {
            swap(result[i], result[result.size() - i - 1]);
        }

        return result;
    }
};
void ClientCode()
{
    Context *context = new Context(new ConcreteStrategyA);
    cout << "Client: Strategy is set to normal sorting.\n";
    context->DoSomeBusinessLogic();
    cout << "\n";
    cout << "Client: Strategy is set to reverse sorting.\n";
    context->set_strategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogic();
    delete context;
}

int main()
{
    ClientCode();
    return 0;
}