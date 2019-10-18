struct Item 
{ 
    int value, weight; 
}; 
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    sort(arr, arr + n, cmp); 

    int curWeight = 0;  
    double finalvalue = 0.0; 
  
    for (int i = 0; i < n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part of it 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
  
    return finalvalue; 
} 