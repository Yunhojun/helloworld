using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class enemyBehaviour : MonoBehaviour
{
    public int HP;
    float time;
    // Start is called before the first frame update
    void Start()
    {
        HP = 100;
        time = 0;
    }

    // Update is called once per frame
    void Update()
    {
        if(HP <= 0)
        {
            Destroy(gameObject);
        }
        time += Time.deltaTime;
        if(time >= 1f)
        {
            display();
        }
    }

    void display()
    {
        time = 0;
    }
}
