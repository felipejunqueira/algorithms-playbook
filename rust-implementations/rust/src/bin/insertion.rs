fn insertion_sort<T: PartialOrd + Copy>(array: &mut[T]) {
    let n = array.len();
    for j in 1..n {
        let key = array[j];
        let mut i = j; // Mutable, so we can change it 
        // We check i > 0 first to avoid the 'usize' underflow crash!
        while i > 0 && array[i-1] > key {
            array[i] = array[i-1];
            i -= 1;
        }
        array[i] = key;
    }
}

fn main() {
    let mut list = vec![5, 9, 1, 5, 6];
    // {:.?} is for alignment/padding, usually {:?} might be enough
    println!("Original: {:.?}", list);
    insertion_sort(&mut list);
    println!("Sorted: {:.?}", list);
}