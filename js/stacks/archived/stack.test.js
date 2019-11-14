const test = require('ava');
const Stack = require('../lib/stack');

test('constructor with array', t => {
  t.plan(1);
  const s = new Stack();
  t.is(s.isEmpty(), true, 'new stack should be empty');
});

test('stack push()', t => {
  t.plan(1);
  const s = new Stack();
  s.push(5);
  t.is(s.size(), 1, 'stack size should be 1 after push');
});

test('stack pop()', t => {
  t.plan(5);
  const s = new Stack();
  const error = t.throws(() => {
    s.pop();
  }, /Stack is empty/);
  t.is(error.message, 'Stack is empty');

  s.push(5);
  t.is(s.size(), 1, 'stack size should be 1 after push');
  const item = s.pop();
  t.is(item, 5, 'pop should return 5');
  t.is(s.size(), 0, 'stack size should be 0 after push and pop');
});

test('stack top()', t => {
  t.plan(2); // t.throws counts as a test
  const s = new Stack();
  const error = t.throws(() => {
    s.top();
  }, /Stack is empty/);
  t.is(error.message, 'Stack is empty');
});

test('new stack pop should throw error', t => {
  t.plan(2);
  const s = new Stack();
  const error = t.throws(() => {
    s.pop();
  }, /Stack is empty/);
  t.is(error.message, 'Stack is empty');
});

test('stack size()', t => {
  t.plan(1);
  const s = new Stack();
  t.is(s.size(), 0, 'new stack size should be 0');
});

test('stack isEmpty()', t => {
  t.plan(1);
  const s = new Stack();
  t.is(s.isEmpty(), true, 'new stack should be empty');
});
