using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerScript : MonoBehaviour
{
    [SerializeField]
    private Animator animator;
    [SerializeField]
    private float Hp = 10;
    [SerializeField]
    private GameObject monster;
   


    // Start is called before the first frame update
    void Start()
    {
        animator = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        AnimatedAttack();
        AnimatedDead();
    }

    public void AnimatedAttack()
    {
        animator.SetBool("attack", Input.GetKeyDown("space"));
    }

    public void AnimatedDead()
    {
        animator.SetFloat("Hp", Hp);
    }
}
