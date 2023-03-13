#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    int64_t n;
    vector<int64_t> arr;
    arr.clear();
    cin >> n;
    for (int64_t i = 0; i < n; i++){
        int64_t temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int64_t length = arr.size() - 1;
    for (int64_t i = length; i >= 0; i--){
        if (i * 2 + 1 > length && i * 2 + 2 > length){
            continue;
        }
        else{
            int64_t k = i;
            while (!(k * 2 + 1 > length && k * 2 + 2 > length)){
                if (k * 2 + 2 > length){
                    if (arr[k] > arr[k * 2 + 1]){
                        swap(arr[k], arr[k * 2 + 1]);
                        k = k * 2 + 1;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if (arr[2 * k + 2] < arr[2 * k + 1]){
                        if (arr[k] > arr[2 * k + 2]){
                            swap(arr[k], arr[2 * k + 2]);
                            k = k * 2 + 2;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        if (arr[k] > arr[2 * k + 1]){
                            swap(arr[k], arr[2 * k + 1]);
                            k = k * 2 + 1;
                        }
                        else{
                            break;
                        }
                    }             
                }
            }
        }
    }

    while (length >= 0){
        cout << arr[0] << ' ';
        if (length == 0){
            break;
        }
        swap(arr[0], arr[length]);
        length--;
        int64_t k = 0;
        while (!(k * 2 + 1 > length && k * 2 + 2 > length)){
            if (k * 2 + 2 > length){
                if (arr[k] > arr[k * 2 + 1]){
                    swap(arr[k], arr[k * 2 + 1]);
                    k = k * 2 + 1;
                }
                else{
                    break;
                }
            }
            else{
                if (arr[2 * k + 2] < arr[2 * k + 1]){
                    if (arr[k] > arr[2 * k + 2]){
                        swap(arr[k], arr[2 * k + 2]);
                        k = k * 2 + 2;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if (arr[k] > arr[2 * k + 1]){
                        swap(arr[k], arr[2 * k + 1]);
                        k = k * 2 + 1;
                    }
                    else{
                        break;
                    }
                }             
            }
        }
    }
    cout << endl;

    return 0;
}