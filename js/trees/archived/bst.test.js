const test = require('ava');
const BST = require('../lib/trees/binarysearchtree');

// error call for Ava
const newBst = () => new BST();

test('BST constructor', t => {
  t.plan(5);
  const errMsg = 'Root node key must be supplied';
  const err = t.throws(() => {
    newBst();
  }, errMsg);
  t.is(err.message, errMsg);

  const bst = new BST(3);
  const tree = bst.getTree();
  const val = tree.key;
  t.is(val, 3, 'should set root node key');
  t.is(bst.left, undefined, 'should set left child to undefined');
  t.is(bst.right, undefined, 'should set right child to undefined');
});

test('BST insert', t => {
  t.plan(6);
  const bst = new BST(50);
  bst.insert(30);
  t.is(bst.getTree().left.key, 30, 'should set left child');
  bst.insert(20);
  t.is(bst.getTree().left.left.key, 20, 'should set left, left child');
  bst.insert(40);
  t.is(bst.getTree().left.right.key, 40, 'should set left, right child');
  bst.insert(70);
  t.is(bst.getTree().right.key, 70, 'should set right child');
  bst.insert(60);
  t.is(bst.getTree().right.left.key, 60, 'should set right, left child');
  bst.insert(80);
  t.is(bst.getTree().right.right.key, 80, 'should set right, right child');
});

test('BST aux functions', t => {
  t.plan(8);
  const bst = new BST(50);
  bst.insert(30);
  t.is(bst.getTree().left.key, 30, 'should set left child');
  bst.insert(20);
  t.is(bst.getTree().left.left.key, 20, 'should set left, left child');
  bst.insert(40);
  t.is(bst.getTree().left.right.key, 40, 'should set left, right child');
  bst.insert(70);
  t.is(bst.getTree().right.key, 70, 'should set right child');
  bst.insert(60);
  t.is(bst.getTree().right.left.key, 60, 'should set right, left child');
  bst.insert(80);
  t.is(bst.getTree().right.right.key, 80, 'should set right, right child');
  const size = bst.sizeOfTree();
  t.is(size, 7, 'size of tree should be 7');
  const height = bst.heightOfTree();
  t.is(height, 3, 'height of tree should be 3');
});
