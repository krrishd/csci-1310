class Number {

    private:
        int *arr;
        int index;
        int size;

    public:

        Number(int s) {
            size = s;
            arr = new int[s];
            index = 0;
            // Fill in the rest of this constructor as needed.
        }

        void addDigit(int dig) {
            if (index < size) {
                arr[index] = dig;
                index++;
            }
            // ex. arr currently = [1, 2], addDigit(5) is called, arr should = [1, 2, 5]
        }

    void printNumber() {
        // print the number such as 124 etc.
        for (int i = 0; i < index; i++) {
            cout << arr[i];
        }
    }

    bool operator>(const Number& n) {
        if (index > n.index) {
            return true;
        } else if (index < n.index) {
            return false;
        } else {
            for (int i = 0; i < index; i++) {
                if (arr[i] > n.arr[i]) {
                    return true;
                }
            }
            return false;
        }
    }
};

void WeatherForecaster::maxHighTemp() {
    int theMaxHighTemp = 0;
    string theMaxHighTempDay;
    for(int i = 0; i < index; i++) {
        if (yearData[i].highTemp > theMaxHighTemp) {
            theMaxHighTemp = yearData[i].highTemp;
            theMaxHighTempDay = yearData[i].day;
        }
    }
    cout << theMaxHighTemp << endl;
}