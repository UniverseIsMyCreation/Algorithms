#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    int64_t n;
    vector<int64_t> arr;
    arr.clear();
    cin >> n;
    int64_t length = 0;
    for (int64_t i = 0; i < n; i++){
        int64_t temp;
        cin >> temp;
        if (temp == 0){
            cin >> temp;
            arr.push_back(temp);
            length++;
            int64_t k = length - 1;
            while (k > 0){
                if (arr[(k-1) / 2] < arr[k]){
                    swap(arr[(k-1) / 2], arr[k]);
                    k = (k-1) / 2;
                }
                else{
                    break;
                }
            }
        }
        else{
            cout << arr[0] << endl;
            swap(arr[0], arr[length - 1]);
            arr.pop_back();
            length--;
            int64_t k = 0;
            int64_t temp_length = length - 1;
            while (!(k * 2 + 1 > temp_length && k * 2 + 2 > temp_length)){
                if (k * 2 + 2 > temp_length){
                    if (arr[k] < arr[k * 2 + 1]){
                        swap(arr[k], arr[k * 2 + 1]);
                        k = k * 2 + 1;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if (arr[2 * k + 2] < arr[2 * k + 1]){
                        if (arr[k] < arr[2 * k + 1]){
                            swap(arr[k], arr[2 * k + 1]);
                            k = k * 2 + 1;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        if (arr[k] < arr[2 * k + 2]){
                            swap(arr[k], arr[2 * k + 2]);
                            k = k * 2 + 2;
                        }
                        else{
                            break;
                        }
                    }             
                }
            }
        }
    }

    return 0;
}