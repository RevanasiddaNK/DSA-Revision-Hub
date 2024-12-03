void countSort(int nums[], int n, int place) {
          
        vector<int>Count(10,0);
        // count array
        for(int i=0; i<n; i++){
            Count[ (nums[i]/place)%10 ]++;
        }
//Cumutalative sum of count
        for(int i=1; i<10; i++){
           Count[i] += Count[i-1];
        }

        int  outputArray[n];
// cumulative count array will have indices to place element at last position of element value
        for(int i=n-1; i>=0; i--){
            outputArray[ Count[ (nums[i]/place)%10  ] - 1 ] = nums[i];
            Count[ (nums[i]/place)%10 ]--;
        }

        for(int i=0; i<n; i++){
            nums[i] = outputArray[i];
        }
        
    }


void radixSort(int arr[], int n) 
{ 
   
   int place = 1;
   int maxi = 0;
   for(int i=0; i<n; i++){
       maxi = max( maxi, arr[i] );
   }
   
   for(int place=1; maxi/place > 0  ; place *= 10){
       countSort(arr,n,place);
   }
   
} 
