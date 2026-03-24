def insert(st, temp):
    # base condition -> checks if the stack is empty and the top <= temp
    if not stack or st[-1] <= temp:
        st.append(temp)
        return
    
    # pops the top to keep a track
    val = st.pop()
    # this call is basically insert the temp recursively
    insert(st, temp)

    # once done inserting the temp in the right place
    # insert the popped values one-by-one
    st.append(val)

def sortStack(st):
    # checks if the stack is present
    if st:
        temp = st.pop()
        sortStack(st)
        insert(st, temp)

if __name__ == "__main__":
    stack = [4, 1, 3, 2]
    sortStack(stack)

    # Print the sorted stack
    print("Sorted stack (descending order):", stack)