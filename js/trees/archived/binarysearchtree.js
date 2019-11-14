class BinarySearchTree {
  constructor(val) {
    if (!val) throw new Error('Root node key must be supplied');

    // private scope
    const root = {
      key: val,
      left: undefined,
      right: undefined,
    };

    function createNode(key) {
      const node = {
        key,
        left: undefined,
        right: undefined,
      };

      return node;
    }

    // handles assigning of node
    function recurse(node, key) {
      if (node === undefined) {
        return createNode(key);
      }

      if (key < node.key) {
        Object.defineProperty(node, 'left', {
          value: recurse(node.left, key),
        });
      } else if (key > node.key) {
        Object.defineProperty(node, 'right', {
          value: recurse(node.right, key),
        });
      }

      return node;
    }

    this.insert = key => recurse(root, key);

    // keep root private, safely deep clone
    this.getTree = () => JSON.parse(JSON.stringify(root));

    function size(node) {
      if (node === undefined) {
        return 0;
      }

      return size(node.left) + 1 + size(node.right);
    }
    // keep root private
    this.sizeOfTree = () => size(root);

    function height(node) {
      if (node === undefined) {
        return 0;
      }

      // compute depth of each branch
      const lDepth = height(node.left);
      const rDepth = height(node.right);

      // use larger one, add one for root
      if (lDepth > rDepth) {
        return lDepth + 1;
      }

      return rDepth + 1;
    }
    this.heightOfTree = () => height(root);
  }
}

module.exports = BinarySearchTree;
