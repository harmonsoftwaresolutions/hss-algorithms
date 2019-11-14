class Stack {
  constructor() {
    // use scope for private property
    const array = [];

    this.push = item => array.push(item);

    this.pop = () => {
      if (this.isEmpty()) {
        throw new Error('Stack is empty');
      }
      const item = array.pop();

      return item;
    };

    this.top = () => {
      if (typeof array[0] === 'undefined') {
        throw new Error('Stack is empty');
      }
      const item = array[0];

      return item;
    };

    this.size = () => {
      const ln = array.length;

      return ln;
    };

    this.isEmpty = () => {
      const check = array.length === 0;

      return check;
    };
  }
}

module.exports = Stack;
