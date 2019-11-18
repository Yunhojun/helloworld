using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class objScript : MonoBehaviour
{
    [SerializeField]
    float f = 5f;
    public bool Pressed = true;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        move();
    }

    void move()
    {
        transform.Translate(Vector3.right * f * Time.deltaTime);
    }

    private void OnBecameInvisible()
    {
        Destroy(gameObject);
    }
}
