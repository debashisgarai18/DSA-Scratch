def insert(st, temp):
    # base condition -> checks if the stack is empty
    if not stack:
        st.append(temp)
        return
    
    # pops the top to keep a track
    val = st.pop()
    # this call is basically insert the temp recursively
    insert(st, temp)

    # once done inserting the temp is done
    # insert the popped values one-by-one
    st.append(val)

def reverseStack(st):
    # checks if the stack is present
    if st:
        temp = st.pop()
        reverseStack(st)
        insert(st, temp)

if __name__ == "__main__":
    stack = [4, 1, 3, 2]
    reverseStack(stack)

    # Print the sorted stack
    print("Reversed stack : ", stack)