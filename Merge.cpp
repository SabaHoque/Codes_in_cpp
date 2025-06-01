 #include <iostream>


void merge(int arr[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int t[k];

    while(i<= mid && j <= h)
    {
        if (arr[i]<= arr[j])
        {
            t[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            t[k] = arr[j];
            j++;
            k++;
        }
    }
        if(i> mid)
        {
           while(j<=h)
           {
               t[k] = arr[j];
            j++;
            k++;
           }
        }
        else
        {
           while(i<= mid)
           {
            t[k] = arr[i];
            i++;
            k++;
           }
           for(k=l; k<=h; k++)
           {
               arr[k]=t[k];
           }
        }
    }

void mergeSort(int arr[], int left, int right) {

    if (left < right) {
        int mid = (right + left) / 2;


        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);


        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cout<<"Enter the value of n = ";
    cin>> n;
    cout<<"Enter the values in array = ";
    int a[n];
    int i =0 ;
     for ( i = 0 ; i <n ; i++)
     {
        cin>>a[i];

        }
    cout << "Original array: ";
    printArray(a, n);

    ms(a, 0, n - 1);

    cout << "Array sorted in decreasing order: ";
    printArray(a, n);

    return 0;
}

