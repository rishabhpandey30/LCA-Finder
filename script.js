function TreeNode(val) {
  this.val = val;
  this.left = null;
  this.right = null;
}

function buildTree(values) {
  if (!values.length || values[0] === "null") return null;

  const nodes = values.map(val => val === "null" ? null : new TreeNode(parseInt(val)));
  let i = 0;

  for (let j = 1; j < nodes.length; j += 2) {
    if (nodes[i]) {
      nodes[i].left = nodes[j] || null;
      nodes[i].right = nodes[j + 1] || null;
    }
    i++;
  }

  return nodes[0];
}

function findLCAHelper(root, p, q) {
  if (!root || root.val === p || root.val === q) return root;
  const left = findLCAHelper(root.left, p, q);
  const right = findLCAHelper(root.right, p, q);
  return left && right ? root : left || right;
}

function findLCA() {
  const input = document.getElementById("treeInput").value.trim().split(",");
  const p = parseInt(document.getElementById("pInput").value);
  const q = parseInt(document.getElementById("qInput").value);

  const root = buildTree(input);
  const lca = findLCAHelper(root, p, q);

  document.getElementById("result").innerText = 
    lca ? `LCA of ${p} and ${q} is ${lca.val}` : `LCA not found or invalid input.`;
}
