vector<int> generateNextPalindromeUtil (vector<int> num, int n )
{
     
    // Find the index of mid digit
    int mid = n / 2;
 
    // A bool variable to check if copy of left
    // side to right is sufficient or not
    bool leftsmaller = false;
 
    // End of left side is always 'mid -1'
    int i = mid - 1;
 
    // Beginning of right side depends
    // if n is odd or even
    int j = (n % 2) ? mid + 1 : mid;
 
   // Initially, ignore the middle same digits 
    while (i >= 0 && num[i] == num[j])
        i--, j++;
 
    // Find if the middle digit(s) need to be
    // incremented or not (or copying left 
    // side is not sufficient)
    if (i < 0 || num[i] < num[j])
        leftsmaller = true;
 
    // Copy the mirror of left to right
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
 
    // Handle the case where middle digit(s) must
    // be incremented. This part of code is for 
    // CASE 1 and CASE 2.2
    if (leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
 
        // If there are odd digits, then increment
        // the middle digit and store the carry
        if (n % 2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
 
        // Add 1 to the rightmost digit of the 
        // left side, propagate the carry towards 
        // MSB digit and simultaneously copying
        // mirror of the left side to the right side.
        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
             
            // Copy mirror to right
            num[j++] = num[i--]; 
        }
    }

    return num;
} 


vector<int> nextsmallestpallindrome(vector<int> num , int n){
	vector<int> ans;
 	if (AreAll9s(num, n))
    {
        ans.push_back(1);
        for(i = 1; i < n; i++)ans.push_back(0);
    }
    else
    {
        ans = generateNextPalindromeUtil(num, n);
    }
    return ans;
 }