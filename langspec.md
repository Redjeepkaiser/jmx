# jmx -- language specification

This is the language specification for the jm* programming language.

## Niche

embedded

## Paradigm

yes:
- procedural
	+ mostly
- metaprogramming
- strongly statically typed
- functional
	+ pattern-matching result analysis

no:
- object-oriented programming
- functional
	+ immutability is not a language feature

## Syntax

### Comments

```
// This is a single-line comment

/*
 This is a
       multi line
    comment.
*/

/**
 * This is a multi-line documentation string.
 */
```


### Variables

```
a = 1;
b = 2;
c = a + b;
```

### Statements

```
// This is a single statement:
// (specifically, it is an expression)
a = 1 + 2 + 3;

// This too is an expression:
a = call_routine();

// This is block-statement
{
	a = 1;
	b = 2;
	do_something();
}

// Here is a control-block-statement:
if (condition) {
	// do something
}
```

Here are all the control blocks:

```
// Condition
if (c) { /* ... */ }

// Match
match (variable) {
	a: {
	
	}
	b: {
	
	}
	// Match multiple possibilities
	c, d: {
	}
}

// Iteration
while (c) { /* ... */ }
do { /* ... */ } while(c); // <-- Iterates before checking condition

```

### Scope

Scope is leaky.
Thus, the following program text is semantically invalid:

```
void routine() {
	int a = 55;
	{
		a = 23;
	}
	print(a); // Expect 23
}
```

### Routines

Routines are the building blocks of a procedural programming language

```

int rtnA() {
	return rtnB() * -3 + 1;
}

int main(int argc, char** argv) {
	return rtnA();
}

int rtnB() {
	return -1;
}

```

## Metaprogramming

### Routines
```

meta int VERSION = 1.3.0;

// Metaprogramming blocks are run in lua
meta rtn {
	-- This is lua!
	
	-- Create a new routine
	prg = jmx.routine.new({
		type_return = jmx.primitives.void,
		name = 'print_version',
		signature = []
	})
	
	-- Append it with a statement
	jmx.routine.append(prg, {
		type = 'call',
		routine = 'println',
		arguments = [ jmx.meta['VERSION'] ]
	})
	
	-- The return value of this program should
	-- contain a routine (as indicated by `rtn`).
	return prg
}
```


### Annotations
```
meta ano @print_all_lines(prg) {
	-- Annotation: print something before and after each line
	-- Also, use shorter syntax for library calls
	
	-- Keep a list of statements
	stms = []
	
	-- Iterate over a routine (statement-by-statement)
	for i,line in jmx.irtn(prg) do
		-- Insert a new statement (method call)
		tables.insert(stms, jmx.nstmcall('print', '>line: '..i))
		-- Insert the original statement
		tables.insert(stms, prg['body'][i])
		-- Insert a new statement (method call)
		tables.insert(stms, jmx.nstmcall('print', '<line: '..i))
	end
	
	-- Set the new body on the program
	prg['body'] = stms
	
	-- There is return statement here
}

@print_all_lines
void routine(int a, int b) {
	int r = 0;

	for(int i = 0; i < a * b; i++) {
		r += i**a + i**b;
	}
	
	return r;
}

// Should be transformed to:
void routine(int a, int b) {
	println('>line 1');
	int r = 0;
	println('<line 1');

	println('>line 2');
	for(int i = 0; i < a * b; i++) {
		r += i**a + i**b;
	}
	println('<line 2');
	
	println('>line 3');
	return r;
  println('<line 3');  // No, this one does not get called,
                       // but it did get generated.
}
```