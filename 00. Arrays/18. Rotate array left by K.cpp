vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    int size = n;
    n = n-1;
    for(int i=0; i<k; i++){
        swap(arr[0], arr[n]);
        n--;

        int j = 0;
        int key = arr[0];
        while(j < n){
            arr[j] = arr[j+1];
            j++;
        }
        arr[j] = key;
    }

    reverse(arr.begin()+size-k, arr.end());
    
    return arr;

}
