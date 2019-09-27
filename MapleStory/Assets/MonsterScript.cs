using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterScript : MonoBehaviour
{
    [SerializeField]
    public float Velocity;
    [SerializeField]
    private Animator animator;
    private bool run = false;
    [SerializeField]
    public float Hp = 1;
    public int IdentificialNumber;

    // Start is called before the first frame update
    void Start()
    {
        animator = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        move();
        AnimatedMove();
        if (Hp <= 0)
        {
            MonsterDead();
        }

        AnimatedDead();
    }

    public void move()
    {
        transform.Translate(new Vector3(-1f, 0, 0) *Velocity * Time.deltaTime); 
    }

    public void AnimatedMove()
    {
        if (Velocity >= 3.0f)
        {
            run = true;
        }
        else
        {
            run = false;
        }
        animator.SetBool("Run", run);
    }

    public void AnimatedDead()
    {
        animator.SetFloat("Hp", Hp);
    }

    public void MonsterDead()
    {
        Velocity = 0;
        transform.position = new Vector3(12, -2, 0);
    }

    public void OnBecameInvisible()
    {
        Hp = 0;
    }
}
