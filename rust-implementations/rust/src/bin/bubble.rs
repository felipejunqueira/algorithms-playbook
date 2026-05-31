// The function assigning uses generics <T>
// 'T:PartialOrd' is a "Trait Bound", we say T can by any type, since
// it has a possible comparison

fn bubble_sort<T: PartialOrd>(list: &mut [T]) {
    let n = list.len();
    if n <= 1 {return;}
    for i in 0..n { // 0...n-1
        let mut flag = 0;
        for j in 0..n-1-i {
            if list[j] > list[j+1] {
                list.swap(j, j+1); // Native from Rust
                flag = 1;
            }
        }
        if flag == 0 {return;}
    }
}

fn main() {
    // 'mut' is a mutable variable, accepting be changed. Safer than C
    // Truly passing by reference
    // ! says it is a Macro
    let mut array = vec![64, 34, 25, 12, 22, 11, 90];
    println!("Before: {:.?}", array); 
    bubble_sort(&mut array); 
    println!("After: {:.?}", array)
}