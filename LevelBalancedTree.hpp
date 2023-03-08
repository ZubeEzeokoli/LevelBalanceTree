#ifndef __PROJ_FOUR_LEVEL_BALANCED_TREE_HPP
#define __PROJ_FOUR_LEVEL_BALANCED_TREE_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};


template<typename Key, typename Value>
class LevelBalancedTree
{
	struct Node{
		Key key;
		Value val;
		Node *left;
		Node *right;

		Node(Key k, Value v, Node *l, Node *r){
			key = k;
			val = v;
			left = l;
			right = r;
		}
		void insert_rebalance(Node *r, unsigned size){
			if(r == nullptr){
				return;
			}
			if(r->left == nullptr && r->right == nullptr){
				return;
			}
			//left side first case in slides ins 20,19,18,12,9
			if(size > 2 && r->right == nullptr && r->left != nullptr){
				if(r->left->left != nullptr && r->left->right == nullptr){
					r->right = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->left->key;
					r->val = r->left->val;
					r->left->key = r->left->left->key;
					r->left->val = r->left->left->val;
					delete r->left->left;
					r->left->left = nullptr;
					}
				else if(r->left->left == nullptr && r->left->right != nullptr){
					r->right = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->left->right->key;
					r->val = r->left->right->val;
					delete r->left->right;
					r->left->right = nullptr;
					}
				}
			//right side first case in slides ins 20,19,18,12,9
			else if(size > 2 && r->right != nullptr && r->left == nullptr){
				if(r->right->right != nullptr && r->right->left == nullptr){
					r->left = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->right->key;
					r->val = r->right->val;
					r->right->key = r->right->right->key;
					r->right->val = r->right->right->val;
					delete r->right->right;
					r->right->right = nullptr;
					}
				if(r->right->right == nullptr && r->right->left != nullptr){
					r->left = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->right->left->key;
					r->val = r->right->left->val;
					delete r->right->left;
					r->right->left = nullptr;
					}
				}
			
			//left side second case in slides ins 17, 7, 5, 13
			else if(size > 5 && r->right->left == nullptr && r->right->right == nullptr){
				if(r->left->left != nullptr && r->left->right != nullptr){
					if(r->left->left->left == nullptr && r->left->left->right == nullptr){
						if(r->left->right->left != nullptr && r->left->right->right == nullptr){
							r->right->right = new Node(r->right->key, r->right->val, nullptr, nullptr);
							r->right->key = r->key;
							r->right->val = r->val;
							r->key = r->left->right->key;
							r->val = r->left->right->val;
							r->left->right->key = r->left->right->left->key;
							r->left->right->val = r->left->right->left->val;
							delete r->left->right->left;
							r->left->right->left = nullptr;
						}
						if(r->left->right->left == nullptr && r->left->right->right != nullptr){
							r->right->right = new Node(r->right->key, r->right->val, nullptr, nullptr);
							r->right->key = r->key;
							r->right->val = r->val;
							r->key = r->left->right->right->key;
							r->val = r->left->right->right->val;
							delete r->left->right->right;
							r->left->right->right = nullptr;
						}
					}
				}
			}

			//right side second case in slides ins 17,7 5, 13
			else if(size > 5 && r->left->right == nullptr && r->left->left == nullptr){
				if(r->right->right != nullptr && r->right->left != nullptr){
					if(r->right->right->right == nullptr && r->right->right->left == nullptr){
						if(r->right->left->right != nullptr && r->right->left->left == nullptr){
							r->left->left = new Node(r->left->key, r->left->val, nullptr, nullptr);
							r->left->key = r->key;
							r->left->val = r->val;
							r->key = r->right->left->key;
							r->val = r->right->left->val;
							r->right->left->key = r->right->left->right->key;
							r->right->left->val = r->right->left->right->val;
							delete r->right->left->right;
							r->right->left->right = nullptr;
						}
						if(r->right->left->right == nullptr && r->right->left->left != nullptr){
							r->left->left = new Node(r->left->key, r->left->val, nullptr, nullptr);
							r->left->key = r->key;
							r->left->val = r->val;
							r->key = r->right->left->left->key;
							r->val = r->right->left->left->val;
							delete r->right->left->left;
							r->right->left->left = nullptr;
						}
					}
				}
			}

			//left side third test case in slides ins 6
			else if(size > 10 && r->left->left != nullptr && r->left->right != nullptr){
				if(r->left->right->left != nullptr && r->left->right->right != nullptr){
					if(r->left->right->left->left == nullptr && r->left->right->left->right == nullptr){
						if(r->left->right->right->left == nullptr && r->left->right->right->right == nullptr){
							if(r->left->left->left != nullptr && r->left->left->right != nullptr){
								if(r->left->left->right->left == nullptr && r->left->left->right->right == nullptr){
									if(r->left->left->left->left == nullptr && r->left->left->left->right != nullptr){
										r->right->right->right = new Node(r->right->right->key, r->right->right->val, nullptr, nullptr);
										r->right->right->key = r->right->key;
										r->right->right->val = r->right->val;
										r->right->key = r->key;
										r->right->val = r->val;
										r->right->left = r->left->right;
										r->key = r->left->key;
										r->val = r->left->val;
										r->left->key = r->left->left->key;
										r->left->val = r->left->left->val;
										r->left->right = new Node(r->left->left->right->key, r->left->left->right->val, nullptr, nullptr);
										r->left->left->key = r->left->left->left->key;
										r->left->left->val = r->left->left->left->val;
										r->left->left->right->key = r->left->left->left->right->key;
										r->left->left->right->val = r->left->left->left->right->val;
										delete r->left->left->left->right;
										r->left->left->left->right = nullptr;
										delete r->left->left->left;
										r->left->left->left = nullptr;
									}
								else if(r->left->left->left->left != nullptr && r->left->left->left->right == nullptr){
										r->right->right->right = new Node(r->right->right->key, r->right->right->val, nullptr, nullptr);
										r->right->right->key = r->right->key;
										r->right->right->val = r->right->val;
										r->right->key = r->key;
										r->right->val = r->val;
										r->right->left = r->left->right;
										r->key = r->left->key;
										r->val = r->left->val;
										r->left->key = r->left->left->key;
										r->left->val = r->left->left->val;
										r->left->right = new Node(r->left->left->right->key, r->left->left->right->val, nullptr, nullptr);
										r->left->left->key = r->left->left->left->key;
										r->left->left->val = r->left->left->left->val;
										r->left->left->left->key = r->left->left->left->left->key;
										r->left->left->left->val = r->left->left->left->left->val;
										delete r->left->left->left->left;
										r->left->left->left->left = nullptr;
										delete r->left->left->right;
										r->left->left->right = nullptr;
									}
								}
							//left side insert 6 type but insert 8
							else if(r->left->left->right->left != nullptr && r->left->left->right->right == nullptr){
									if(r->left->left->left->left == nullptr && r->left->left->left->right == nullptr){
										r->right->right->right = new Node(r->right->right->key, r->right->right->val, nullptr, nullptr);
										r->right->right->key = r->right->key;
										r->right->right->val = r->right->val;
										r->right->key = r->key;
										r->right->val = r->val;
										r->right->left = r->left->right;
										r->key = r->left->key;
										r->val = r->left->val;
										r->left->key = r->left->left->right->left->key;
										r->left->val = r->left->left->right->left->val;
										r->left->right = new Node(r->left->left->right->key, r->left->left->right->val, nullptr, nullptr);
										delete r->left->left->right->left;
										r->left->left->right->left = nullptr;
										delete r->left->left->right;
										r->left->left->right = nullptr;
									}
								}
							else if(r->left->left->right->left == nullptr && r->left->left->right->right != nullptr){
									if(r->left->left->left->left == nullptr && r->left->left->left->right == nullptr){
										r->right->right->right = new Node(r->right->right->key, r->right->right->val, nullptr, nullptr);
										r->right->right->key = r->right->key;
										r->right->right->val = r->right->val;
										r->right->key = r->key;
										r->right->val = r->val;
										r->right->left = r->left->right;
										r->key = r->left->key;
										r->val = r->left->val;
										r->left->key = r->left->left->right->key;
										r->left->val = r->left->left->right->val;
										r->left->right = new Node(r->left->left->right->right->key, r->left->left->right->right->val, nullptr, nullptr);
										delete r->left->left->right->right;
										r->left->left->right->right = nullptr;
										delete r->left->left->right;
										r->left->left->right = nullptr;
									}
								}
							}
						}
					}
				}
			}
			
			//right size third test case in slides ins 6
			else if(size > 10 && r->right->right != nullptr && r->right->left != nullptr){
				if(r->right->left->right != nullptr && r->right->left->left != nullptr){
					if(r->right->left->right->right == nullptr && r->right->left->right->left == nullptr){
						if(r->right->left->left->right == nullptr && r->right->left->left->left == nullptr){
							if(r->right->right->right != nullptr && r->right->right->left != nullptr){
								if(r->right->right->left->right == nullptr && r->right->right->left->left == nullptr){
									if(r->right->right->right->right == nullptr && r->right->right->right->left != nullptr){
										r->left->left->left = new Node(r->left->left->key, r->left->left->val, nullptr, nullptr);
										r->left->left->key = r->left->key;
										r->left->left->val = r->left->val;
										r->left->key = r->key;
										r->left->val = r->val;
										r->left->right = r->right->left;
										r->key = r->right->key;
										r->val = r->right->val;
										r->right->key = r->right->right->key;
										r->right->val = r->right->right->val;
										r->right->left = new Node(r->right->right->left->key, r->right->right->left->val, nullptr, nullptr);
										r->right->right->key = r->right->right->right->key;
										r->right->right->val = r->right->right->right->val;
										r->right->right->left->key = r->right->right->right->left->key;
										r->right->right->left->val = r->right->right->right->left->val;
										delete r->right->right->right->left;
										r->right->right->right->left = nullptr;
										delete r->right->right->right;
										r->right->right->right = nullptr;
									}
								else if(r->right->right->right->right != nullptr && r->right->right->right->left == nullptr){
										r->left->left->left = new Node(r->left->left->key, r->left->left->val, nullptr, nullptr);
										r->left->left->key = r->left->key;
										r->left->left->val = r->left->val;
										r->left->key = r->key;
										r->left->val = r->val;
										r->left->right = r->right->left;
										r->key = r->right->key;
										r->val = r->right->val;
										r->right->key = r->right->right->key;
										r->right->val = r->right->right->val;
										r->right->left = new Node(r->right->right->left->key, r->right->right->left->val, nullptr, nullptr);
										r->right->right->key = r->right->right->right->key;
										r->right->right->val = r->right->right->right->val;
										r->right->right->right->key = r->right->right->right->right->key;
										r->right->right->right->val = r->right->right->right->right->val;
										delete r->right->right->right->right;
										r->right->right->right->right = nullptr;
										delete r->right->right->left;
										r->right->right->left = nullptr;
									}
								}
							else if(r->right->right->left->right != nullptr && r->right->right->left->left == nullptr){
									if(r->right->right->right->right == nullptr && r->right->right->right->left == nullptr){
										r->left->left->left = new Node(r->left->left->key, r->left->left->val, nullptr, nullptr);
										r->left->left->key = r->left->key;
										r->left->left->val = r->left->val;
										r->left->key = r->key;
										r->left->val = r->val;
										r->left->right = r->right->left;
										r->key = r->right->key;
										r->val = r->right->val;
										r->right->key = r->right->right->left->right->key;
										r->right->val = r->right->right->left->right->val;
										r->right->left = new Node(r->right->right->left->key, r->right->right->left->val, nullptr, nullptr);
										delete r->right->right->left->right;
										r->right->right->left->right = nullptr;
										delete r->right->right->left;
										r->right->right->left = nullptr;
									}
								}
							else if(r->right->right->left->right == nullptr && r->right->right->left->left != nullptr){
									if(r->right->right->right->right == nullptr && r->right->right->right->left == nullptr){
										r->left->left->left = new Node(r->left->left->key, r->left->left->val, nullptr, nullptr);
										r->left->left->key = r->left->key;
										r->left->left->val = r->left->val;
										r->left->key = r->key;
										r->left->val = r->val;
										r->left->right = r->right->left;
										r->key = r->right->key;
										r->val = r->right->val;
										r->right->key = r->right->right->left->key;
										r->right->val = r->right->right->left->val;
										r->right->left = new Node(r->right->right->left->left->key, r->right->right->left->left->val, nullptr, nullptr);
										delete r->right->right->left->left;
										r->right->right->left->left = nullptr;
										delete r->right->right->left;
										r->right->right->left = nullptr;
									}
								}
							}
						}
					}
				}
			}

			//left side delete 87
			else if(size > 3 && r->left != nullptr && r->right == nullptr){
				if(r->left->left != nullptr && r->left->right != nullptr){
					r->right = new Node(r->key, r->val, nullptr, nullptr);
					r->right->left = new Node(r->left->right->key, r->left->right->val, nullptr, nullptr);
					r->key = r->left->key;
					r->val = r->left->val;
					r->left->key = r->left->left->key;
					r->left->val = r->left->left->val;
					delete r->left->left;
					delete r->left->right;
					r->left->left = nullptr;
					r->left->right = nullptr;
				}
			}

			insert_rebalance(r->left, size);
			insert_rebalance(r->right, size);
		}

		void remove_rebalance(Node *r, unsigned size){
			if(r == nullptr){
				return;
			}
			if(r->left == nullptr && r->right == nullptr){
				return;
			}

			//left side delete 87
			else if(size > 3 && r->left != nullptr && r->right == nullptr){
				if(r->left->left != nullptr && r->left->right != nullptr){
					r->right = new Node(r->key, r->val, nullptr, nullptr);
					r->right->left = new Node(r->left->right->key, r->left->right->val, nullptr, nullptr);
					r->key = r->left->key;
					r->val = r->left->val;
					r->left->key = r->left->left->key;
					r->left->val = r->left->left->val;
					delete r->left->left;
					delete r->left->right;
					r->left->left = nullptr;
					r->left->right = nullptr;
				}
				else if(r->left->left != nullptr && r->left->right == nullptr){
					r->right = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->left->key;
					r->val = r->left->val;
					r->left->key = r->left->left->key;
					r->left->val = r->left->left->val;
					delete r->left->left;
					r->left->left = nullptr;
				}
				else if(r->left->left == nullptr && r->left->right != nullptr){
					r->right = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->left->right->key;
					r->val = r->left->right->val;
					delete r->left->right;
					r->left->right = nullptr;
				}
			}

			//right side delete 87
			else if(size > 3 && r->left == nullptr && r->right != nullptr){
				if(r->right->right != nullptr && r->right->left != nullptr){
					r->left = new Node(r->key, r->val, nullptr, nullptr);
					r->left->right = new Node(r->right->left->key, r->right->left->val, nullptr, nullptr);
					r->key = r->right->key;
					r->val = r->right->val;
					r->right->key = r->right->right->key;
					r->right->val = r->right->right->val;
					delete r->right->right;
					delete r->right->left;
					r->right->right = nullptr;
					r->right->left = nullptr;
				}
				else if(r->right->right != nullptr && r->right->left == nullptr){
					r->left = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->right->key;
					r->val = r->right->val;
					r->right->key = r->right->right->key;
					r->right->val = r->right->right->val;
					delete r->right->right;
					r->right->right = nullptr;
				}
				else if(r->right->right == nullptr && r->right->left != nullptr){
					r->left = new Node(r->key, r->val, nullptr, nullptr);
					r->key = r->right->left->key;
					r->val = r->right->left->val;
					delete r->right->left;
					r->right->left = nullptr;
				}
			}

			//left side delete 2,5,12
			else if(size > 5 && r->left->left == nullptr && r->left->right == nullptr){
				if(r->right->left != nullptr && r->right->right != nullptr && r->right->right->right != nullptr){
					r->left->left = new Node(r->left->key, r->left->val, nullptr, nullptr);
					r->left->key = r->key;
					r->left->val = r->val;
					r->left->right = r->right->left;
					r->key = r->right->key;
					r->val = r->right->val;
					Node *temp = r->right->right;
					delete r->right;
					r->right = temp;
				}
				else if(r->right->left != nullptr && r->right->right != nullptr){
					if(r->right->left->left != nullptr && r->right->left->right != nullptr){
						r->left->left = new Node(r->left->key, r->left->val, nullptr, nullptr);
						r->left->key = r->key;
						r->left->val = r->val;
						r->key = r->right->left->key;
						r->val = r->right->left->val;
						r->right->left->key = r->right->left->right->key;
						r->right->left->val = r->right->left->right->val;
						r->left->right = new Node(r->right->left->left->key, r->right->left->left->val, nullptr, nullptr);
						delete r->right->left->right;
						delete r->right->left->left;
						r->right->left->right = nullptr;
						r->right->left->left = nullptr;
					}
					else if(r->right->left->left == nullptr && r->right->left->right != nullptr){
						r->left->left = new Node(r->left->key, r->left->val, nullptr, nullptr);
						r->left->key = r->key;
						r->left->val = r->val;
						r->key = r->right->left->key;
						r->val = r->right->left->val;
						r->right->left->key = r->right->left->right->key;
						r->right->left->val = r->right->left->right->val;
						delete r->right->left->right;
						r->right->left->right = nullptr;
					}
					else if(r->right->left->left != nullptr && r->right->left->right == nullptr){
						r->left->left = new Node(r->left->key, r->left->val, nullptr, nullptr);
						r->left->key = r->key;
						r->left->val = r->val;
						r->key = r->right->left->key;
						r->val = r->right->left->val;
						r->left->right = new Node(r->right->left->left->key, r->right->left->left->val, nullptr, nullptr);
						delete r->right->left->left;
						r->right->left->left = nullptr;
						delete r->right->left;
						r->right->left = nullptr;
					}
				}
			}

			//right side delete 2,5,12
			else if(size > 5 && r->right->right == nullptr && r->right->left == nullptr){
				if(r->left->right != nullptr && r->left->left != nullptr && r->left->left->left != nullptr){
					r->right->right = new Node(r->right->key, r->right->val, nullptr, nullptr);
					r->right->key = r->key;
					r->right->val = r->val;
					r->right->left = r->left->right;
					r->key = r->left->key;
					r->val = r->left->val;
					Node *temp = r->left->left;
					delete r->left;
					r->left = temp;
				}
				else if(r->left->right != nullptr && r->left->left != nullptr){
					if(r->left->right->right != nullptr && r->left->right->left != nullptr){
						r->right->right = new Node(r->right->key, r->right->val, nullptr, nullptr);
						r->right->key = r->key;
						r->right->val = r->val;
						r->key = r->left->right->key;
						r->val = r->left->right->val;
						r->left->right->key = r->left->right->left->key;
						r->left->right->val = r->left->right->left->val;
						r->right->left = new Node(r->left->right->right->key, r->left->right->right->val, nullptr, nullptr);
						delete r->left->right->left;
						delete r->left->right->right;
						r->left->right->left = nullptr;
						r->left->right->right = nullptr;
					}
					else if(r->left->right->right == nullptr && r->left->right->left != nullptr){
						r->right->right = new Node(r->right->key, r->right->val, nullptr, nullptr);
						r->right->key = r->key;
						r->right->val = r->val;
						r->key = r->left->right->key;
						r->val = r->left->right->val;
						r->left->right->key = r->left->right->left->key;
						r->left->right->val = r->left->right->left->val;
						delete r->left->right->left;
						r->left->right->left = nullptr;
					}
					else if(r->left->right->right != nullptr && r->left->right->left == nullptr){
						r->right->right = new Node(r->right->key, r->right->val, nullptr, nullptr);
						r->right->key = r->key;
						r->right->val = r->val;
						r->key = r->left->right->key;
						r->val = r->left->right->val;
						r->right->left = new Node(r->left->right->right->key, r->left->right->right->val, nullptr, nullptr);
						delete r->left->right->right;
						r->left->right->right = nullptr;
						delete r->left->right;
						r->left->right = nullptr;
					}
				}
			}

			remove_rebalance(r->left, size);
			remove_rebalance(r->right, size);
		}

		Node *insert_node(Node *r, const Key k, Value v){
			if(r == nullptr){
				r = new Node(k, v, nullptr, nullptr);
				return r;
			}
			if(k < r->key && r->left == nullptr){
				r->left = new Node(k, v, nullptr, nullptr);
				return r;
			}

			if(r->key < k && r->right == nullptr){
				r->right = new Node(k, v, nullptr, nullptr);
				return r;
			}
			if(k < r->key){
				insert_node(r->left, k ,v);
			}
			else if(r->key < k){
				insert_node(r->right, k ,v);
			}
			return r;
		}

		Node *successor(Node *r){
			Node *suc = r;
			if(suc != nullptr && suc->left != nullptr){
				suc = suc->left;
			}
			return suc;
		}

		void remove_node(Node*r, Node *par, const Key k){
			while(r != nullptr){
				if(r->key == k){
					if(r->left == nullptr && r->right == nullptr){
						if(par == nullptr){
							r = nullptr;
						}
						else if(par->left == r){
							delete par->left;
							par->left = nullptr;
						}
						else{
							delete par->right;
							par->right = nullptr;
						}
					}
					else if(r->left == nullptr){
						if(par == nullptr){
							r = r->right;
						}
						else if(par->left == r){
							Node *temp = r->right;
							delete par->left;
							par->left = temp;
						}
						else{
							Node *temp = r->right;
							delete par->right;
							par->right = temp;
						}
					}
					else if(r->right == nullptr){
						if(par == nullptr){
							r = r->left;
						}
						else if(par->left == r){
							Node *temp = r->left;
							delete par->left;
							par->left = temp;
						}
						else{
							Node *temp = r->left;
							delete par->right;
							par->right = temp;
						}
					}
					else{
						Node *suc = r->successor(r->right);
						r->key = suc->key;
						r->val = suc->val;
						par = r;
						remove_node(r->right, par, suc->key);
					}
					return;
				}

			else if(k < r->key){
				par = r;
				r = r->left;
				}
			
			else if(r->key < k){
				par = r;
				r = r->right;
				}
			}

		}
	};

private:
	// fill in private member data here
	// If you need to declare private functions, do so here too.
	Node *root;
	size_t distinct_keys;
	void destroy(Node*r);
	bool exists(Node *r, const Key k) const noexcept;
	void find_val(Node *r, const Key k, Value &temp_val);
	void const_find_val(Node *r, const Key k, Value &temp_val) const;
	//struct Node* insert_node(Node *r, const Key k, Value v);
	void io(Node *r, std::vector<Key> &vk) const;
	void po(Node *r, std::vector<Key> &vk) const;
	void preo(Node *r, std::vector<Key> &vk) const;
public:
	LevelBalancedTree();

	// In general, a copy constructor and assignment operator
	// are good things to have.
	// For this quarter, I am not requiring these. 
	//	LevelBalancedTree(const LevelBalancedTree & st);
	//	LevelBalancedTree & operator=(const LevelBalancedTree & st);


	// The destructor is required. 
	~LevelBalancedTree();

	// size() returns the number of distinct keys in the tree.
	size_t size() const noexcept;

	// isEmpty() returns true if and only if the tree has no values in it. 
	bool isEmpty() const noexcept;

	// contains() returns true if and only if there
	//  is a (key, value) pair in the tree
	//	that has the given key as its key.
	bool contains(const Key & k) const noexcept; 

	// find returns the value associated with the given key
	// If !contains(k), this will throw an ElementNotFoundException
	// There needs to be a version for const and non-const LevelBalancedTrees.
	Value & find(const Key & k);
	const Value & find(const Key & k) const;

	// Inserts the given key-value pair into 
	// the tree and performs the balancing operation(s) if needed
	// operation, as described in lecture. 
	// If the key already exists in the tree, 
	// you may do as you please (no test cases in
	// the grading script will deal with this situation)
	void insert(const Key & k, const Value & v);


	// Deletes the given key from the tree
	// and performs the balancing operation(s) if needed.
	// If the key does not exist in the tree, 
	// do not modify the tree.
	void remove(const Key &k);


	// The following three functions all return
	// the set of keys in the tree as a standard vector.
	// Each returns them in a different order.
	std::vector<Key> inOrder() const;
	std::vector<Key> preOrder() const;
	std::vector<Key> postOrder() const;


};

template<typename Key, typename Value>
void LevelBalancedTree<Key,Value>::destroy(Node *r){
	if(r != nullptr){
		destroy(r->left);
		destroy(r->right);
		delete r;
	}
}

template<typename Key, typename Value>
bool LevelBalancedTree<Key,Value>::exists(Node *r, const Key k) const noexcept
{
	if(r == nullptr){
		return false;
	}

	if(r->key == k){
		return true;
	}

	if(exists(r->left, k)){
		return true;
	}
	return exists(r->right, k);
}


template<typename Key, typename Value>
void LevelBalancedTree<Key,Value>::find_val(Node *r, const Key k, Value &temp_val)
{
	if(r == nullptr){
		return;
	}

	if(r->key == k){
		temp_val = r->val;
		return;
	}
	if(k < r->key){
		find_val(r->left, k, temp_val);
	}
	else if(r->key < k){
		find_val(r->right, k, temp_val);
	}
}

template<typename Key, typename Value>
void LevelBalancedTree<Key,Value>::const_find_val(Node *r, const Key k, Value &temp_val) const
{
	if(r == nullptr){
		return;
	}

	if(r->key == k){
		temp_val = r->val;
		return;
	}
	if(k < r->key){
		const_find_val(r->left, k, temp_val);
	}
	else if(r->key < k){
		const_find_val(r->right, k, temp_val);
	}
}

template<typename Key, typename Value>
void LevelBalancedTree<Key,Value>::io(Node *r, std::vector<Key> &vk) const
{
	if(r == nullptr){
		return;
	}

	io(r->left, vk);
	vk.push_back(r->key);
	io(r->right, vk);
}

template<typename Key, typename Value>
void LevelBalancedTree<Key,Value>::po(Node *r, std::vector<Key> &vk) const
{
	if(r == nullptr){
		return;
	}

	po(r->left, vk);
	po(r->right, vk);
	vk.push_back(r->key);
}

template<typename Key, typename Value>
void LevelBalancedTree<Key,Value>::preo(Node *r, std::vector<Key> &vk) const
{
	if(r == nullptr){
		return;
	}

	vk.push_back(r->key);
	preo(r->left, vk);
	preo(r->right, vk);
}

template<typename Key, typename Value>
LevelBalancedTree<Key,Value>::LevelBalancedTree()
{
	this->root = nullptr;
	this->distinct_keys = 0;
}

template<typename Key, typename Value>
LevelBalancedTree<Key,Value>::~LevelBalancedTree()
{
	destroy(this->root);
}

template<typename Key, typename Value>
size_t LevelBalancedTree<Key, Value>::size() const noexcept
{
	return this->distinct_keys;
}

template<typename Key, typename Value>
bool LevelBalancedTree<Key, Value>::isEmpty() const noexcept
{
	if(this->size() == 0){
		return true;
	}
	return false;
}


template<typename Key, typename Value>
bool LevelBalancedTree<Key, Value>::contains(const Key &k) const noexcept
{
	return this->exists(this->root, k);
}



template<typename Key, typename Value>
Value & LevelBalancedTree<Key, Value>::find(const Key & k)
{	
	if(!this->contains(k)){
		throw ElementNotFoundException("key not in the tree");
	}
	static Value temp_val;
	find_val(this->root, k, temp_val);
	return temp_val;
}

template<typename Key, typename Value>
const Value & LevelBalancedTree<Key, Value>::find(const Key & k) const
{
	if(!this->contains(k)){
		throw ElementNotFoundException("key not in the tree");
	}
	static Value temp_val;
	const_find_val(this->root, k, temp_val);
	const Value &const_temp_val = temp_val;
	return const_temp_val; 
}

template<typename Key, typename Value>
void LevelBalancedTree<Key, Value>::insert(const Key & k, const Value & v)
{
	if(this->contains(k)){
		return;
	}
	this->distinct_keys++;
	this->root = this->root->insert_node(this->root, k ,v);
	this->root->insert_rebalance(this->root, this->size());

	return; 	
}

template<typename Key, typename Value>
void LevelBalancedTree<Key, Value>::remove(const Key &k)
{
	if(!this->contains(k)){
		return;
	}
	this->distinct_keys --;
	Node *par = nullptr;
	this->root->remove_node(this->root, par, k);
	this->root->remove_rebalance(this->root, this->size());
	return;
}



template<typename Key, typename Value>
std::vector<Key> LevelBalancedTree<Key, Value>::inOrder() const
{
	std::vector<Key> vk;
	this->io(this->root, vk);
	return vk; 
}


template<typename Key, typename Value>
std::vector<Key> LevelBalancedTree<Key, Value>::preOrder() const
{
	std::vector<Key> vk;
	this->preo(this->root, vk);
	return vk; 
}


template<typename Key, typename Value>
std::vector<Key> LevelBalancedTree<Key, Value>::postOrder() const
{
	std::vector<Key> vk;
	this->po(this->root, vk);
	return vk; 
}







#endif 
