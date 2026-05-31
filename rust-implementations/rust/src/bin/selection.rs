// Now, let's sort structs, not only ints arrays
// 'derive' is a powerful  attribute in rust
// It automatically implements "Traits" (interfaces) for the struct
// Debug: allows printing with {:?}
// PartialEq: allows checking if two structs are equal
// PartialOrd: allows comparisons
#[derive(Debug, PartialEq, PartialOrd)]
// The compiler compares fields in the order they appear in the struct definition

struct Software {
    // Rust compares structs field by field in the order they are defined
    version: f32,
    name: String
    // Just swap the fields to change the sorting
}

fn selection_sort<T: PartialOrd>(list: &mut [T]) {
    let n = list.len();

    for i in 0..n {
        let mut min_idx = i;
        for j in (i+1)..n { //  Are the limits right here?
            if list[j] < list[min_idx] {min_idx = j;}
        }
        list.swap(i, min_idx);
    }
}

fn main() {
    // vec! is a macro that creates a Vector (heap-allocated array)
    // We use .to_string() because "Name" is a string literal ($str),
    // but our struct expects an owned String
    let mut apps = vec![
        Software { version: 2.0, name: "RustAnalyzer".to_string() },
        Software { version: 1.2, name: "Cargo".to_string() },
        Software { version: 5.5, name: "Vscode".to_string() },
        Software { version: 0.8, name: "BetaApp".to_string() }
    ];

    println!("--- Before Sorting ---");
    println!("{:#?}", apps); // Adds "pretty-print" (newlines and indentation)

    selection_sort(&mut apps);

    println!("--- After Sorting ---");
    println!("{:#?}", apps);

}