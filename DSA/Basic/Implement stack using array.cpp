void MyStack ::push(int x) {
    // Your Code
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if(top != -1){
        int num = arr[top--];
        return num;
    }else{
        return -1;
    }
}
